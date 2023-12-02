#include "../include/philo.h"


int get_sem_value(sem_t *sem)
{
    int value;

    sem_getvalue(sem, &value);
    return value;
}


void phil_eat(t_phil *phil)
{
    phil->state = EATING;

    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "waiting for the waiter permit", NULL);
    sem_wait(phil->philo->sem_waiter);
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "has got the waiter permit", NULL);
    sem_wait(phil->philo->sem_forks);
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "has taken a fork", NULL);
    sem_wait(phil->philo->sem_forks);
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "has taken a fork", NULL);
    phil_set_last_meal_time(phil, get_current_time_ms(&(phil->philo)));
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "is eating", COLOR_GREEN);
    usleep(phil->philo->time_to_eat * 1000);
    phil->meals_eaten += 1;
    sem_post(phil->philo->sem_forks);
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "has released a fork", NULL);
    sem_post(phil->philo->sem_forks);
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "has released a fork", NULL);
    sem_post(phil->philo->sem_waiter);
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "has posted to the waiter semaphore", NULL);

}

void phil_sleep(t_phil *phil)
{
    phil->state = SLEEPING;
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "is sleeping", COLOR_BLUE);
    usleep(phil->philo->time_to_sleep * 1000);
}

void phil_think(t_phil *phil)
{
    if (phil->state == THINKING)
        return ;
    phil->state = THINKING;
    phil_print_state(get_current_time_ms(&(phil->philo)), phil, "is thinking", COLOR_YELLOW);
}

void *death_checker(void *args)
{
    t_phil *phil;
    long last_meal_time;
    long now;
    //int i;

    phil = (t_phil *)args;
    while (1)
    {
        last_meal_time = phil_get_last_meal_time(phil);
        now = get_current_time_ms(&(phil->philo));
        if (now - last_meal_time >= phil->philo->time_to_die)
        {
            phil_print_state(now, phil, "is dying...", COLOR_RED);
            phil->state = DEAD;
            sem_post(phil->philo->sem_simterm);
            // i = 0;
            // while (i < phil->philo->number_of_phils)
            // {
            //     sem_post(phil->philo->sem_simterm);
            //     i++;
            // }
            phil_print_state(now, phil, "died", COLOR_RED);
            break ;
        }
        usleep(2000);
    }
    return (NULL);
}

// void *death_handler(void *args)
// {
//     t_phil *phil;

//     phil = (t_phil *)args;
//     sem_wait(phil->philo->sem_simterm);
//     philo_free(&(phil->philo));
//     exit(0);
// }

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
        // pthread_create(&(phil->death_handler), NULL, death_handler,
        //         (void *)phil);
        // pthread_detach(phil->death_handler);
        while (phil->meals_eaten < phil->philo->number_of_meals
                || phil->philo->number_of_meals < 0)
        {
            phil_think(phil);
            phil_eat(phil);
            phil_sleep(phil);
        }
    }
    return (phil->pid);
}