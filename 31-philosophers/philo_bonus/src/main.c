#include "../include/philo.h"

#define phil_count 5
#define meal_count 10
#define t_die 800
#define t_eat 200
#define t_sleep 200

void *kill_children(void *args)
{
    t_philo *philo;
    int i;

    philo = (t_philo *)args;
    sem_wait(philo->sem_death_checker);
    i = 0;
    while (i < philo->number_of_phils)
    {
        kill(philo->phils[i].pid, SIGTERM);
        i++;
    }
    return (NULL);
}


int main(void)
{
    t_philo *philo;
    int i;
    int pid;

    philo = philo_init();
    if (!philo)
        return (1);
    philo->number_of_meals = meal_count;
    philo->number_of_phils = phil_count;
    philo->time_to_die = t_die;
    philo->time_to_eat = t_eat;
    philo->time_to_sleep = t_sleep;
    philo_init_and_set_phils(philo, philo->number_of_phils);
    philo_init_and_set_semaphores(philo, philo->number_of_phils);
    philo->timestamp_simstart = get_current_time_ms(NULL);
    i = 0;
    while (i < philo->number_of_phils)
    {
        pid = phil_process_start(&(philo->phils[i]));
        if (pid == 0)
            break ;
        i++;
    }
    if (pid != 0)
    {
        // pthread_create(&(philo->death_checker), NULL, kill_children, NULL);
        // pthread_detach(philo->death_checker);
    }

    if (pid != 0)
    {
        i = 0;
        while (i < philo->number_of_phils)
        {
            waitpid(philo->phils[i].pid, &(philo->phils[0].pstatus), 0);
            i++;
        }
    }
    //sem_post(philo->sem_death_checker);
    philo_free(&philo);
    return 0;
}
