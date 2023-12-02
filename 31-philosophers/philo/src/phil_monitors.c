#include "../include/philo.h"

int allowed_to_eat(t_phil *phil)
{
    int allowed_to_eat;

    if (is_any_dead(phil->philo) || phil->philo->number_of_phils < 2)
        return (0);
    pthread_mutex_lock(&(phil->philo->mutex_waiter));
    allowed_to_eat = (
            !(phil->left_phil->state == EATING || phil->right_phil->state == EATING)
            && (phil->last_meal_time <= phil->left_phil->last_meal_time)
            && (phil->last_meal_time <= phil->right_phil->last_meal_time)
            );
    pthread_mutex_unlock(&(phil->philo->mutex_waiter));
    if (allowed_to_eat)
    {
        pthread_mutex_lock(&(phil->left_fork->mutex));
        pthread_mutex_lock(&(phil->right_fork->mutex));
    }
    return (allowed_to_eat);
}

int is_any_dead(t_philo *philo)
{
    int flag_death;

    pthread_mutex_lock(&(philo->mutex_death));
    flag_death = philo->is_any_dead;
    pthread_mutex_unlock(&(philo->mutex_death));
    return (flag_death);
}
