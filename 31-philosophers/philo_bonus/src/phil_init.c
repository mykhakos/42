/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:50:03 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/25 17:16:48 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_phil	*phils_init(int count)
{
	t_phil	*phils;
	int		id;

	phils = malloc(sizeof(t_phil) * count);
	if (phils == NULL)
		return (NULL);
	id = 0;
	while (id < count)
	{
		if (pthread_mutex_init(&(phils[id].last_meal_time_mutex), NULL) != 0)
			return (NULL); // add free here later
		if (pthread_mutex_init(&(phils[id].mutex_log), NULL) != 0)
			return (NULL);
		phils[id].id = id + 1;
		phils[id].last_meal_time = get_current_time_ms(NULL);
		phils[id].meals_eaten = 0;
		phils[id].state = UNKNOWN;
		phils[id].philo = NULL;
		phils[id].sem_phil_finished = NULL;
		id++;
	}
	return (phils);
}

void	phils_set_philo(t_phil *phils, t_philo *philo, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		phils[i].philo = philo;
		phils[i].sem_phil_finished = philo->sem_phil_finished[i];
		i++;
	}
}

void	phils_free(t_phil **phils, int count)
{
	int	i;

	if (phils != NULL && *phils != NULL)
	{
		i = 0;
		while (i < count)
		{
			(*phils)[i].philo = NULL;
			pthread_mutex_destroy(&((*phils)[i].mutex_log));
			pthread_mutex_destroy(&((*phils)[i].last_meal_time_mutex));
			i++;
		}
		free(*phils);
		*phils = NULL;
	}
}
