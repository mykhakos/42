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
    printf("%s%ld %i %s%s\n",
            color_code, timestamp, phil->id, state, COLOR_DEFAULT);
    pthread_mutex_unlock(&(phil->philo->mutex_log));
}

t_phil *phil_left(t_phil *phil)
{
    int num_phils;
    int left_phil_index;
    
    num_phils = phil->philo->number_of_phils;
    left_phil_index = (phil->id - 1 + num_phils) % num_phils;
    return (&(phil->philo->phils[left_phil_index]));
}

t_phil *phil_right(t_phil *phil)
{
    int num_phils;
    int right_phil_index;
    
    num_phils = phil->philo->number_of_phils;
    right_phil_index  = (phil->id + 1) % num_phils;
    return (&(phil->philo->phils[right_phil_index]));
}
