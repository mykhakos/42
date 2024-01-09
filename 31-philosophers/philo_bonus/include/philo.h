/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:13:14 by kmykhail          #+#    #+#             */
/*   Updated: 2023/12/06 18:14:59 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>

# define ARGV_IDX_PHIL_COUNT 1
# define ARGV_IDX_T_DIE 2
# define ARGV_IDX_T_EAT 3
# define ARGV_IDX_T_SLEEP 4
# define ARGV_IDX_MEAL_COUNT 5

# define COLOR_GREEN "\033[32m"
# define COLOR_BLUE "\033[34m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_RED "\033[31m"
# define COLOR_DEFAULT "\033[0m"

# define SEM_FORKS_NAME "/philo_forks"
# define SEM_WAITER_NAME "/philo_waiter"
# define SEM_LOG_NAME "/philo_log"
# define SEM_DEATH_CHECKER_NAME "/philo_death_checker"
# define SEM_SIMTERM "/philo_simterm"
# define SEM_PHIL_FINISHED "/philo_phil_finished"

typedef enum e_phil_state
{
    UNKNOWN,
    THINKING,
    EATING,
    SLEEPING,
    DEAD,
} t_phil_state;

typedef struct s_phil
{
    pid_t pid;
    int pstatus;
    pthread_t death_checker;
    pthread_t death_handler;
    int id;
    int meals_eaten;
    long last_meal_time;
    pthread_mutex_t last_meal_time_mutex;
    pthread_mutex_t mutex_log;
    enum e_phil_state state;
    struct s_philo *philo;
    sem_t *sem_phil_finished;
} t_phil;

typedef struct s_philo
{
    int number_of_phils;
    int number_of_meals;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long timestamp_simstart;
    int is_any_dead;
    t_phil *phils;
    sem_t *sem_forks;
    sem_t *sem_log;
    sem_t *sem_waiter;
    sem_t *sem_death_checker;
    sem_t *sem_simterm;
    sem_t *sem_phil_finished[200];
    pthread_mutex_t mutex_is_any_dead;
    pthread_t death_checker;
} t_philo;

t_philo *philo_init(void);
int philo_init_and_set_phils(t_philo *philo, int count);
int philo_init_and_set_semaphores(t_philo *philo, int phil_count);
void philo_free(t_philo **philo);

t_phil	*phils_init(int count);
void	phils_set_philo(t_phil *phils, t_philo *philo, int count);
void	phils_free(t_phil **phils, int count);
t_phil *phil_left(t_phil *phil);
t_phil *phil_right(t_phil *phil);
int phil_is_allowed_to_eat(t_phil *phil);
int is_any_dead(t_philo *philo);
void phil_log(t_phil *phil, char *msg, const char *color_code);
void *phil_routine(void *arg_phil);

int	ft_atoi(const char *str);
long get_current_time_ms(t_philo **philo);

sem_t *sem_safeopen(char *sem_name, int sem_value);
void sem_safeclose(sem_t **sem, char *sem_name);

long phil_get_last_meal_time(t_phil *phil);
void phil_set_last_meal_time(t_phil *phil, long timestamp);
int  phil_process_start(t_phil *phil);

int get_is_any_dead(t_philo *philo);
void set_is_any_dead(t_philo *philo, int value);

#endif
