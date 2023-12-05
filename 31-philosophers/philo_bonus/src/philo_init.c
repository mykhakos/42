#include "../include/philo.h"


t_philo *philo_init(void)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    philo->time_to_die = 0;
    philo->time_to_eat = 0;
    philo->time_to_sleep = 0;
    philo->number_of_meals = 0;
    philo->number_of_phils = 0;
    philo->phils = NULL;
    philo->sem_forks = NULL;
    philo->sem_waiter = NULL;
    philo->sem_log = NULL;
    return (philo);
}

int philo_init_and_set_phils(t_philo *philo, int phil_count)
{
    t_phil *phils;

    phils = phils_init(phil_count);
    if (!phils)
    {
        perror("phils_init (malloc)");
        return (1);
    }
    philo->phils = phils;
    phils_set_philo(phils, philo, phil_count);
    return (0);
}

int philo_init_and_set_semaphores(t_philo *philo, int phil_count)
{
    philo->sem_forks = sem_safeopen(SEM_FORKS_NAME, phil_count);
    if (!philo->sem_forks)
        return (1);
    philo->sem_waiter = sem_safeopen(SEM_WAITER_NAME, phil_count / 2);
    if (!philo->sem_waiter)
        return (1);
    philo->sem_log = sem_safeopen(SEM_LOG_NAME, 1);
    if (!philo->sem_log)
        return (1);
    philo->sem_death_checker = sem_safeopen(SEM_DEATH_CHECKER_NAME, 1);
    if (!philo->sem_death_checker)
        return (1);
    philo->sem_simterm = sem_safeopen(SEM_SIMTERM, 0);
    if (!philo->sem_simterm)
        return (1);
    return (0);
}

void philo_free(t_philo **philo)
{
    if (philo != NULL && *philo != NULL)
    {
        phils_free(&((*philo)->phils), (*philo)->number_of_phils);
        (*philo)->phils = NULL;
        sem_safeclose(&((*philo)->sem_forks), SEM_FORKS_NAME);
        sem_safeclose(&((*philo)->sem_waiter), SEM_WAITER_NAME);
        sem_safeclose(&((*philo)->sem_log), SEM_LOG_NAME);
        sem_safeclose(&((*philo)->sem_death_checker), SEM_DEATH_CHECKER_NAME);
        sem_safeclose(&((*philo)->sem_simterm), SEM_SIMTERM);
        free(*philo);
        *philo = NULL;
    }
}
