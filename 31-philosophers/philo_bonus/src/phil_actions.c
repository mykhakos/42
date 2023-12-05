#include "../include/philo.h"


void phil_eat(t_phil *phil)
{
    phil->state = EATING;

    sem_wait(phil->philo->sem_waiter);
    sem_wait(phil->philo->sem_forks);
    phil_log(phil, "has taken a fork", COLOR_DEFAULT);
    sem_wait(phil->philo->sem_forks);
    phil_log(phil, "has taken a fork", COLOR_DEFAULT);
    phil_set_last_meal_time(phil, get_current_time_ms(&(phil->philo)));
    phil_log(phil, "is eating", COLOR_GREEN);
    phil->meals_eaten += 1;
    usleep(phil->philo->time_to_eat * 1000);
    sem_post(phil->philo->sem_forks);
    sem_post(phil->philo->sem_forks);
    sem_post(phil->philo->sem_waiter);
}

void phil_sleep(t_phil *phil)
{
    phil->state = SLEEPING;
    phil_log(phil, "is sleeping", COLOR_BLUE);
    usleep(phil->philo->time_to_sleep * 1000);
}

void phil_think(t_phil *phil)
{
    if (phil->state == THINKING)
        return ;
    phil->state = THINKING;
    phil_log(phil, "is thinking", COLOR_YELLOW);
}

void *death_checker(void *args)
{
    t_phil *phil;
    long last_meal_time;
    long now;

    phil = (t_phil *)args;
    while (phil->meals_eaten < phil->philo->number_of_meals
            || phil->philo->number_of_meals < 0)
    {
        sem_wait(phil->philo->sem_death_checker);
        last_meal_time = phil_get_last_meal_time(phil);
        now = get_current_time_ms(&(phil->philo));
        if (now - last_meal_time >= phil->philo->time_to_die)
        {
            phil->state = DEAD;
            phil_log(phil, "died", COLOR_RED);
            sem_post(phil->philo->sem_log);
            int i = 0;
            while (i < phil->philo->number_of_phils)
            {
                sem_post(phil->philo->sem_simterm);
                i++;
            }
            break ;
        }
        sem_post(phil->philo->sem_death_checker);
        usleep(2000);
    }
    return (NULL);
}

void *death_handler(void *args)
{
    t_phil *phil;

    phil = (t_phil *)args;
    sem_wait(phil->philo->sem_simterm);
    philo_free(&(phil->philo));
    exit(0);
}

int phil_process_start(t_phil *phil)
{
    phil->pid = fork();
    if (phil->pid == -1)
    {
        perror("fork");
        philo_free(&(phil->philo));
        exit(EXIT_FAILURE);
    }
    if (phil->pid == 0)
    {
        pthread_create(&(phil->death_checker), NULL, death_checker,
                (void *)phil);
        pthread_detach(phil->death_checker);
        pthread_create(&(phil->death_handler), NULL, death_handler,
                (void *)phil);
        pthread_detach(phil->death_handler);
        while (phil->meals_eaten < phil->philo->number_of_meals
                || phil->philo->number_of_meals < 0)
        {
            phil_think(phil);
            phil_eat(phil);
            phil_sleep(phil);
        }
        philo_free(&(phil->philo));
        exit(EXIT_SUCCESS);
    }
    return (phil->pid);
}