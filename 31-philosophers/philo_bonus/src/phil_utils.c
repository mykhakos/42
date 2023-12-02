#include "../include/philo.h"

void phil_log(
        long timestamp,
        t_phil *phil,
        const char *state,
        const char *color_code)
{
    if (!color_code)
        color_code = COLOR_DEFAULT;
    sem_wait(phil->philo->sem_log);
    printf("%s%04ld\t%i\t%s%s\n",
            color_code, timestamp - phil->philo->timestamp_simstart, phil->id, state, COLOR_DEFAULT);
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
