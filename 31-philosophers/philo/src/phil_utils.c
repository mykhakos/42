#include "../include/philo.h"

void phil_print_state(
        long timestamp,
        t_phil *phil,
        const char *state,
        const char *color_code)
{
    if (!color_code)
        color_code = COLOR_DEFAULT;
    pthread_mutex_lock(&(phil->philo->mutex_log));
    printf("%s%04ld %i %s%s\n",
            color_code,
            timestamp - phil->philo->simtime_start,
            phil->id,
            state,
            COLOR_DEFAULT);
    pthread_mutex_unlock(&(phil->philo->mutex_log));
}

