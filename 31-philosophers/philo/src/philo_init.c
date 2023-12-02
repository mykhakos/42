#include "../include/philo.h"

static int philo_init_mutex(t_philo **philo, pthread_mutex_t *mutex)
{
    if (pthread_mutex_init(mutex, NULL) != 0)
    {
        free(*philo);
        *philo = NULL;
        return (1);
    }
    return (0);
}

t_philo *philo_init(void)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    if (philo_init_mutex(&philo, &(philo->mutex_log)) != 0)
        return (NULL);
    if (philo_init_mutex(&philo, &(philo->mutex_waiter)) != 0)
        return (NULL);
    if (philo_init_mutex(&philo, &(philo->mutex_death)) != 0)
        return (NULL);
    philo->time_to_die = 0;
    philo->time_to_eat = 0;
    philo->time_to_sleep = 0;
    philo->timestamp_simstart = 0;
    philo->number_of_meals = 0;
    philo->number_of_phils = 0;
    philo->is_any_dead = 0;
    philo->phils = NULL;
    philo->forks = NULL;
    return (philo);
}

int philo_init_and_set_phils(t_philo *philo, int count)
{
    t_phil *phils;

    phils = phils_init(count);
    if (!phils)
    {
        perror("phils_init (malloc)");
        return (1);
    }
    philo->phils = phils;
    phils_set_neighbors(phils, count);
    phils_set_philo(phils, philo, count);
    return (0);
}

int philo_init_and_set_forks(t_philo *philo, int count)
{
    t_fork *forks;

    forks = forks_init(count);
    if (!forks)
    {
        perror("forks_init (malloc)");
        return (1);
    }
    philo->forks = forks;
    return (0);
}

void philo_free(t_philo **philo)
{
    if (philo != NULL && *philo != NULL)
    {
        pthread_mutex_destroy(&((*philo)->mutex_log));
        pthread_mutex_destroy(&((*philo)->mutex_waiter));
        pthread_mutex_destroy(&((*philo)->mutex_death));
        phils_free(&((*philo)->phils), (*philo)->number_of_phils);
        (*philo)->phils = NULL;
        forks_free(&((*philo)->forks), (*philo)->number_of_phils);
        (*philo)->forks = NULL;
        free(*philo);
        *philo = NULL;
    }
}
