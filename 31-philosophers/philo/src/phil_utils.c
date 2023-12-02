#include "../include/philo.h"

void phil_log(t_phil *phil, char *msg, const char *color_code)
{
    long timestamp_now;
    long time_diff;

    timestamp_now = get_current_time_ms(&(phil->philo));
    time_diff = timestamp_now - phil->philo->timestamp_simstart;
    if (!color_code)
        color_code = COLOR_DEFAULT;
    pthread_mutex_lock(&(phil->philo->mutex_log));
    printf("%s%04ld %i %s%s\n",
            color_code, time_diff, phil->id, msg, COLOR_DEFAULT);
    pthread_mutex_unlock(&(phil->philo->mutex_log));
}
