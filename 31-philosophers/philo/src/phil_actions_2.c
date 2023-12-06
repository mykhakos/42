#include "../include/philo.h"


int phil_sleep(t_phil *phil)
{
    if (get_is_any_dead(phil->philo))
        return (0);
    phil_set_state(phil, SLEEPING);
    phil_log(phil, "is sleeping", COLOR_BLUE);
    usleep(phil->philo->time_to_sleep * 1000);
    return (1);
}

int phil_think(t_phil *phil)
{
    if (get_is_any_dead(phil->philo))
        return (0);
    if (phil_get_state(phil) != THINKING)
    {
        phil_set_state(phil, THINKING);
        phil_log(phil, "is thinking", COLOR_YELLOW);
    }
    return (1);
}

int phil_die(t_phil *phil)
{
    long timestamp_now;
    long timestamp_last_meal_time;

    timestamp_now = get_current_time_ms(&(phil->philo));
    timestamp_last_meal_time = phil_get_last_meal_time(phil);
    if (timestamp_now - timestamp_last_meal_time < phil->philo->time_to_die)
        return (0);
    if (get_is_any_dead(phil->philo))
        return (1);
    set_is_any_dead(phil->philo, 1);
    phil_set_state(phil, DEAD);
    usleep(500);
    phil_log(phil, "died", COLOR_RED);
    return (1);
}

void *phil_routine(void *arg_phil)
{
    t_phil *phil;

    phil = (t_phil *)arg_phil;
    while (phil->meals_eaten < phil->philo->number_of_meals
            || phil->philo->number_of_meals < 0)
    {
        if (phil_is_allowed_to_eat(phil))
        {
            if (!phil_eat(phil))
                break ;
            if (!phil_sleep(phil))
                break ;
        }            
        if (!phil_think(phil))
            break ;
        if (get_is_any_dead(phil->philo))
            break ;
        if (phil_die(phil))
            break ;
        if (get_is_any_dead(phil->philo))
            break ;
        usleep(2000);
    }
    return (NULL);
}
