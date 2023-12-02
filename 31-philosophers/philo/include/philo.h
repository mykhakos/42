/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:13:14 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/25 17:17:36 by kmykhail         ###   ########.fr       */
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

typedef struct s_fork
{
    pthread_mutex_t mutex;
} t_fork;

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
    pthread_t thread;
    int id;
    int meals_eaten;
    long last_meal_time;
    enum e_phil_state state;
    pthread_mutex_t mutex_last_meal_time;
    pthread_mutex_t mutex_state;
    struct s_fork *left_fork;
    struct s_fork *right_fork;
    struct s_phil *left_phil;
    struct s_phil *right_phil;
    struct s_philo *philo;
} t_phil;

typedef struct s_philo
{
    int is_any_dead;
    int number_of_phils;
    int number_of_meals;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long timestamp_simstart;
    t_phil *phils;
    t_fork *forks;
    pthread_mutex_t mutex_log;
    pthread_mutex_t mutex_waiter;
    pthread_mutex_t mutex_is_any_dead;
} t_philo;

t_philo *philo_init(void);
int philo_init_and_set_phils_and_forks(t_philo *philo, int count);
void philo_free(t_philo **philo);

t_fork	*forks_init(int count);
void	forks_free(t_fork **forks, int count);

t_phil	*phils_init(int count);
void	phils_set_forks(t_phil *phils, t_fork *forks, int count);
void	phils_set_neighbors(t_phil *phils, int count);
void	phils_set_philo(t_phil *phils, t_philo *philo, int count);
void	phils_free(t_phil **phils, int count);
int phil_is_allowed_to_eat(t_phil *phil);
int get_is_any_dead(t_philo *philo);
void set_is_any_dead(t_philo *philo, int value);

void phil_log(t_phil *phil, char *msg, const char *color_code);
t_phil_state phil_get_state(t_phil *phil);
void phil_set_state(t_phil *phil, t_phil_state state);
long phil_get_last_meal_time(t_phil *phil);
void phil_set_last_meal_time(t_phil *phil, long timestamp);
void *phil_routine(void *arg_phil);

int	ft_atoi(const char *str);
long get_current_time_ms(t_philo **philo);
int mutex_safeinit(pthread_mutex_t *mutex, void **free_on_error);

#endif
