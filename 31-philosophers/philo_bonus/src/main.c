#include "../include/philo.h"

#define phil_count 5
#define meal_count -1
#define t_die 3000
#define t_eat 1000
#define t_sleep 1000


int main(void)
{
    t_philo *philo;
    int i;

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
    philo->simtime_start = get_current_time_ms(NULL);
    i = 0;
    while (i < philo->number_of_phils)
    {
        phil_process_start(&(philo->phils[i]));
        i++;
    }
    sem_wait(philo->sem_simterm);
    i = 0;
    while (i < philo->number_of_phils)
    {
        kill(philo->phils[i].pid, SIGTERM);
        //waitpid(philo->phils[i].pid, &(philo->phils[0].pstatus), 0);
        i++;
    }
    philo_free(&philo);
    return 0;
}
