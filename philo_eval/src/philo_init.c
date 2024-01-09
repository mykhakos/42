/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:46:34 by kmykhail          #+#    #+#             */
/*   Updated: 2024/01/09 16:46:49 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*philo_init(void)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	if (mutex_safeinit(&(philo->mutex_log), (void **)&philo) != 0
		|| mutex_safeinit(&(philo->mutex_waiter), (void **)&philo) != 0
		|| mutex_safeinit(&(philo->mutex_is_any_dead), (void **)&philo) != 0)
		return (NULL);
	philo->number_of_phils = 0;
	philo->number_of_meals = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->timestamp_simstart = 0;
	philo->is_any_dead = 0;
	philo->phils = NULL;
	philo->forks = NULL;
	return (philo);
}

int	philo_init_and_set_phils_and_forks(t_philo *philo, int count)
{
	t_phil	*phils;
	t_fork	*forks;

	phils = phils_init(count);
	if (!phils)
	{
		perror("phils_init (malloc)");
		return (1);
	}
	forks = forks_init(count);
	if (!forks)
	{
		perror("forks_init (malloc)");
		return (1);
	}
	philo->phils = phils;
	philo->forks = forks;
	phils_set_neighbors(phils, count);
	phils_set_forks(phils, forks, count);
	phils_set_philo(phils, philo, count);
	return (0);
}

void	philo_free(t_philo **philo)
{
	if (philo != NULL && *philo != NULL)
	{
		pthread_mutex_destroy(&((*philo)->mutex_log));
		pthread_mutex_destroy(&((*philo)->mutex_waiter));
		pthread_mutex_destroy(&((*philo)->mutex_is_any_dead));
		if ((*philo)->phils != NULL)
		{
			phils_free(&((*philo)->phils), (*philo)->number_of_phils);
			(*philo)->phils = NULL;
		}
		if ((*philo)->forks != NULL)
		{
			forks_free(&((*philo)->forks), (*philo)->number_of_phils);
			(*philo)->forks = NULL;
		}
		free(*philo);
		*philo = NULL;
	}
}
