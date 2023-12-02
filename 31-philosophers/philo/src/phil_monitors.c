#include "../include/philo.h"

int allowed_to_eat(t_phil *phil)
{
    int allowed_to_eat;
    long last_meal_time;

    if (get_is_any_dead(phil->philo) || phil->philo->number_of_phils < 2)
        return (0);
    pthread_mutex_lock(&(phil->philo->mutex_waiter));
    last_meal_time = phil_get_last_meal_time(phil);
    allowed_to_eat = (
            phil_get_state(phil->left_phil) != EATING 
            && phil_get_state(phil->right_phil) != EATING
            && last_meal_time <= phil_get_last_meal_time(phil->left_phil)
            && last_meal_time <= phil_get_last_meal_time(phil->right_phil)
            );
    pthread_mutex_unlock(&(phil->philo->mutex_waiter));
    return (allowed_to_eat);
}

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
