#include "../include/philo.h"

int get_is_any_dead(t_philo *philo)
{
    int is_any_dead;

    pthread_mutex_lock(&(philo->mutex_is_any_dead));
    is_any_dead = philo->is_any_dead;
    pthread_mutex_unlock(&(philo->mutex_is_any_dead));
    return (is_any_dead);
}

void set_is_any_dead(t_philo *philo, int value)
{
    pthread_mutex_lock(&(philo->mutex_is_any_dead));
    philo->is_any_dead = value;
    pthread_mutex_unlock(&(philo->mutex_is_any_dead));
}