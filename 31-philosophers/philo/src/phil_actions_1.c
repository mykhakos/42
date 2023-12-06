#include "../include/philo.h"


static void phil_select_forks(
        t_phil *phil,
        pthread_mutex_t *fork_take_first,
        pthread_mutex_t *fork_take_second)
{
    if (phil->id == phil->philo->number_of_phils)
    {
        *fork_take_first = phil->left_fork->mutex;
        *fork_take_second = phil->right_fork->mutex;
    }
    else
    {
        *fork_take_first = phil->right_fork->mutex;
        *fork_take_second = phil->left_fork->mutex;
    }
}

static int phil_take_forks(
        t_phil *phil,
        pthread_mutex_t *fork_take_first,
        pthread_mutex_t *fork_take_second)
{
    pthread_mutex_lock(fork_take_first);
    phil_log(phil, "has taken a fork", COLOR_DEFAULT);
    if (get_is_any_dead(phil->philo))
    {
        pthread_mutex_unlock(fork_take_first);
        return (0);
    }
    pthread_mutex_lock(fork_take_second);
    phil_log(phil, "has taken a fork", COLOR_DEFAULT);
    if (get_is_any_dead(phil->philo))
    {
        pthread_mutex_unlock(fork_take_first);
        pthread_mutex_unlock(fork_take_second);
        return (0);
    }
    return (1);
}

int phil_eat(t_phil *phil)
{
    pthread_mutex_t fork_take_first;
    pthread_mutex_t fork_take_second;

    phil_set_state(phil, EATING);
    if (get_is_any_dead(phil->philo))
        return (0);
    phil_select_forks(phil, &fork_take_first, &fork_take_second);
    if (!phil_take_forks(phil, &fork_take_first, &fork_take_second))
        return (0);
    phil_log(phil, "is eating", COLOR_GREEN);
    phil_set_last_meal_time(phil, get_current_time_ms(&(phil->philo)));
    phil->meals_eaten += 1;
    usleep(phil->philo->time_to_eat * 1000);
    pthread_mutex_unlock(&fork_take_first);
    pthread_mutex_unlock(&fork_take_second);
    return (1);
}
