#include "../include/philo.h"

int phil_eat(t_phil *phil, long timestamp)
{
    int eaten;

    eaten = 0;
    if (!is_any_dead(phil->philo))
    {
        phil->state = EATING;
        phil->last_meal_time = timestamp;
        phil_print_state(timestamp, phil, "has taken a fork", NULL);
        if (!is_any_dead(phil->philo))
        {
            phil_print_state(timestamp, phil, "has taken a fork", NULL);
            if (!is_any_dead(phil->philo))
            {
                phil_print_state(timestamp, phil, "is eating", COLOR_GREEN);
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

int phil_sleep(t_phil *phil, long timestamp)
{
    int slept;

    slept = 0;
    if (is_any_dead(phil->philo))
        return (slept);
    slept = 1;
    phil->state = SLEEPING;
    phil_print_state(timestamp, phil, "is sleeping", COLOR_BLUE);
    usleep(phil->philo->time_to_sleep * 1000);
    return (slept);
}

int phil_think(t_phil *phil, long timestamp)
{
    int thought;

    thought = 0;
    if (is_any_dead(phil->philo))
        return (thought);
    thought = 1;
    if (phil->state == THINKING)
        return (thought);
    phil->state = THINKING;
    phil_print_state(timestamp, phil, "is thinking", COLOR_YELLOW);
    return (thought);
}

int phil_die(t_phil *phil, long timestamp)
{
    int died;

    died = 1;
    if (is_any_dead(phil->philo))
        return (died);
    if (timestamp - phil->last_meal_time < phil->philo->time_to_die)
        return (!died);
    phil->state = DEAD;
    pthread_mutex_lock(&(phil->philo->mutex_death));
    phil->philo->is_any_dead = 1;
    pthread_mutex_unlock(&(phil->philo->mutex_death));
    phil_print_state(timestamp, phil, "died", COLOR_RED);
    return (died);
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
            if (!phil_eat(phil, get_current_time_ms(&(phil->philo))))
                break ;
            if (!phil_sleep(phil, get_current_time_ms(&(phil->philo))))
                break ;
        }            
        if (!phil_think(phil, get_current_time_ms(&(phil->philo))))
            break ;
        if (phil_die(phil, get_current_time_ms(&(phil->philo))))
            break ;
        if (is_any_dead(phil->philo))
            break ;
        usleep(2000);
    }
    return (NULL);
}
