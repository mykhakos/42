#include "../include/philo.h"

t_philo *init_philo(void)
{
    t_philo *philo;

    philo = malloc(sizeof(philo));
    if (!philo)
        return (NULL);
    if (pthread_mutex_init(&philo->log_mutex, NULL) != 0)
    {
        free(philo);
        return (NULL);
    }
    philo->number_of_meals = 0;
    philo->number_of_philosophers = 0;
    philo->philosophers = NULL;
    philo->forks = NULL;
    philo->time_to_die = 0;
    philo->time_to_eat = 0;
    philo->time_to_sleep = 0;
    return (philo);
}

void free_philo(t_philo **philo)
{
    if (philo != NULL && *philo != NULL)
    {
        pthread_mutex_destroy(&((*philo)->log_mutex));
        (*philo)->philosophers = NULL;
        (*philo)->forks = NULL;
        free(*philo);
        *philo = NULL;
    }
}
