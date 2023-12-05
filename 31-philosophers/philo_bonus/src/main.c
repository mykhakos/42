#include "../include/philo.h"

#define phil_count 1
#define meal_count 2
#define t_die 410
#define t_eat 2300
#define t_sleep 100


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
        i++;
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
    philo_free(&philo);
    return 0;
}
