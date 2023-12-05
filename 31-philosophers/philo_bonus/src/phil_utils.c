#include "../include/philo.h"

void phil_log(t_phil *phil, char *msg, const char *color_code)
{
    long timestamp_now;
    long time_diff;

    timestamp_now = get_current_time_ms(&(phil->philo));
    time_diff = timestamp_now - phil->philo->timestamp_simstart;
    if (!color_code)
        color_code = COLOR_DEFAULT;
    sem_wait(phil->philo->sem_log);
    pthread_mutex_lock(&(phil->mutex_log));
    if (!msg)
        printf("no msg\n");
    //printf("%s%04ld %i %s%s\n",
    //        color_code, time_diff, phil->id, msg, COLOR_DEFAULT);
    pthread_mutex_unlock(&(phil->mutex_log));
    sem_post(phil->philo->sem_log);
}

long phil_get_last_meal_time(t_phil *phil)
{
    long timestamp;

    pthread_mutex_lock(&(phil->last_meal_time_mutex));
    timestamp = phil->last_meal_time;
    pthread_mutex_unlock(&(phil->last_meal_time_mutex));
    return (timestamp);
}

void phil_set_last_meal_time(t_phil *phil, long timestamp)
{
    pthread_mutex_lock(&(phil->last_meal_time_mutex));
    phil->last_meal_time = timestamp;
    pthread_mutex_unlock(&(phil->last_meal_time_mutex));
}
