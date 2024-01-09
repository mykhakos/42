#include "../include/philo.h"


int phil_eat(t_phil *phil)
{
    if (get_is_any_dead(phil->philo))
        return (0);
    sem_wait(phil->philo->sem_waiter);
    phil->state = EATING;
    if (get_is_any_dead(phil->philo))
    {
        sem_post(phil->philo->sem_waiter);
        return (0);
    }
    sem_wait(phil->philo->sem_forks);
    if (get_is_any_dead(phil->philo))
    {
        sem_post(phil->philo->sem_waiter);
        sem_post(phil->philo->sem_forks);
        return (0);
    }
    phil_log(phil, "has taken a fork", COLOR_DEFAULT);
    sem_wait(phil->philo->sem_forks);
    if (get_is_any_dead(phil->philo))
    {
        sem_post(phil->philo->sem_waiter);
        sem_post(phil->philo->sem_forks);
        sem_post(phil->philo->sem_forks);
        return (0);
    }
    phil_log(phil, "has taken a fork", COLOR_DEFAULT);
    phil_set_last_meal_time(phil, get_current_time_ms(&(phil->philo)));
    if (get_is_any_dead(phil->philo))
    {
        sem_post(phil->philo->sem_waiter);
        sem_post(phil->philo->sem_forks);
        sem_post(phil->philo->sem_forks);
        return (0);
    }
    phil_log(phil, "is eating", COLOR_GREEN);
    phil->meals_eaten += 1;
    usleep(phil->philo->time_to_eat * 1000);
    sem_post(phil->philo->sem_forks);
    sem_post(phil->philo->sem_forks);
    sem_post(phil->philo->sem_waiter);
    return (1);
}

int phil_sleep(t_phil *phil)
{
    if (get_is_any_dead(phil->philo))
        return (0);
    phil->state = SLEEPING;
    phil_log(phil, "is sleeping", COLOR_BLUE);
    usleep(phil->philo->time_to_sleep * 1000);
    return (1);
}

int phil_think(t_phil *phil)
{
    if (get_is_any_dead(phil->philo))
        return (0);
    if (phil->state == THINKING)
        return (1);
    phil->state = THINKING;
    phil_log(phil, "is thinking", COLOR_YELLOW);
    return (1);
}

void notify_about_death(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->number_of_phils)
    {
        sem_post(philo->sem_simterm);
        i++;
    }
}

void *death_checker(void *args)
{
    t_phil *phil;
    long last_meal_time;
    long now;

    phil = (t_phil *)args;
    while (1)
    {
        if (get_is_any_dead(phil->philo))
        {
            return (NULL);
        }
        last_meal_time = phil_get_last_meal_time(phil);
        now = get_current_time_ms(&(phil->philo));
        //sem_wait(phil->philo->sem_death_checker);
        if (now - last_meal_time >= phil->philo->time_to_die)
        {
            phil_log(phil, "died", COLOR_RED);
            set_is_any_dead(phil->philo, 1);

 

            notify_about_death(phil->philo);
            sem_post(phil->philo->sem_death_checker);
            philo_free(&(phil->philo));
            // exit(0);
            break ;
        }
        usleep(500);
    }
    return (NULL);
}

void *death_handler(void *args)
{
    t_phil *phil;

    phil = (t_phil *)args;
    sem_wait(phil->philo->sem_simterm);
    set_is_any_dead(phil->philo, 1);
    usleep(1000);
    //printf("%i received notif\n", phil->id);
    
    sem_post(phil->philo->sem_waiter);
    sem_post(phil->philo->sem_forks);
    sem_post(phil->philo->sem_forks);
    philo_free(&(phil->philo));
    exit(0);
    return (NULL);
}

int phil_process_start(t_phil *phil)
{
    phil->pid = fork();
    if (phil->pid == -1)
        return (-1);
    if (phil->pid == 0)
    {
        pthread_create(&(phil->death_checker), NULL, death_checker,
                (void *)phil);
        pthread_detach(phil->death_checker);
        pthread_create(&(phil->death_handler), NULL, death_handler,
                (void *)phil);
        pthread_detach(phil->death_handler);
        // usleep(1000000);
        // return (0);
        while (phil->meals_eaten < phil->philo->number_of_meals
                || phil->philo->number_of_meals < 0)
        {
            if (!phil_think(phil))
                break ;
            if (!phil_eat(phil))
                break ;
            if (!phil_sleep(phil))
                break ;
            if (get_is_any_dead(phil->philo))
                break ;
        }
        //set_is_any_dead(phil->philo, 1);
        //
        //pthread_join(phil->death_checker, NULL);
        //for (int i = 0; i < phil->philo->number_of_phils; i++)
        //    sem_post(phil->sem_phil_finished);
        
        //pthread_join(phil->death_handler, NULL);
        //printf("%i main ret\n", phil->id);
    }
    return (phil->pid);
}