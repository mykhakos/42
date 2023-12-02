#include "../include/philo.h"

int phil_eat(t_phil *phil)
{
    int eaten;

    eaten = 0;
    if (!get_is_any_dead(phil->philo))
    {
        phil->state = EATING;
        phil->last_meal_time = get_current_time_ms(&(phil->philo));
        phil_log(phil, "has taken a fork", COLOR_DEFAULT);
        if (!get_is_any_dead(phil->philo))
        {
            phil_log(phil, "has taken a fork", COLOR_DEFAULT);
            if (!get_is_any_dead(phil->philo))
            {
                phil_log(phil, "is eating", COLOR_GREEN);
                usleep(phil->philo->time_to_eat * 1000);
                phil->meals_eaten += 1;
                eaten = 1;

            }
        }
    }
    pthread_mutex_unlock(&(phil->right_fork->mutex));
    pthread_mutex_unlock(&(phil->left_fork->mutex));
    return (eaten);
}

int phil_sleep(t_phil *phil)
{
    if (get_is_any_dead(phil->philo))
        return (0);
    phil->state = SLEEPING;
    phil_log(phil, "is sleeping", COLOR_BLUE);
    usleep(phil->philo->time_to_sleep * 1000);
    return (1);
}

int phil_think(t_phil *phil)
{
    if (get_is_any_dead(phil->philo))
        return (0);
    if (phil->state != THINKING)
    {
        phil->state = THINKING;
        phil_log(phil, "is thinking", COLOR_YELLOW);
    }
    return (1);
}

int phil_die(t_phil *phil)
{
    long timestamp_now;

    if (get_is_any_dead(phil->philo))
        return (1);
    timestamp_now = get_current_time_ms(&(phil->philo));
    if (timestamp_now - phil->last_meal_time < phil->philo->time_to_die)
        return (0);
    set_is_any_dead(phil->philo, 1);
    phil->state = DEAD;
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

        if (allowed_to_eat(phil))
        {
            if (!phil_eat(phil))
                break ;
            if (!phil_sleep(phil))
                break ;
        }            
        if (!phil_think(phil))
            break ;
        if (phil_die(phil))
            break ;
        if (get_is_any_dead(phil->philo))
            break ;
        usleep(2000);
    }
    return (NULL);
}
