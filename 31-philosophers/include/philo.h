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

typedef struct s_fork
{
    pthread_mutex_t mutex;
} t_fork;

typedef struct s_philosopher
{
    pthread_t thread;
    int id;
    int meals_eaten;
    unsigned long long last_meal_time;
    struct s_fork *left_fork;
    struct s_fork *right_fork;
    struct s_philo *philo;
} t_philosopher;

typedef struct s_philo
{
    t_philosopher *philosophers;
    t_fork *forks;
    unsigned int number_of_philosophers;
    unsigned long long time_to_die;
    unsigned long long time_to_eat;
    unsigned long long time_to_sleep;
    unsigned int number_of_meals;
    pthread_mutex_t log_mutex;
} t_philo;

t_philo *init_philo(void);
void free_philo(t_philo **philo);

t_fork	*init_forks(int count);
void	free_forks(t_fork **forks, int count);

t_philosopher	*phils_init(int count);
void	phils_set_forks(t_philosopher *phils, t_fork *forks, int count);
void	phils_set_philo(t_philosopher *phils, t_philo *philo, int count);
void	phils_free(t_philosopher **phils, int count);

#endif
