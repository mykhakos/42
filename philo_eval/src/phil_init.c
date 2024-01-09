/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:50:03 by kmykhail          #+#    #+#             */
/*   Updated: 2024/01/09 16:45:44 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_phil	*phils_init(int count)
{
	t_phil	*phils;
	int		i;

	phils = malloc(sizeof(t_phil) * count);
	if (phils == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (mutex_safeinit(&(phils[i].mutex_state), (void **)&phils) != 0)
			return (NULL);
		if (mutex_safeinit(&(phils[i].mutex_last_meal_time), (void **)&phils))
			return (NULL);
		phils[i].id = i + 1;
		phils[i].last_meal_time = 0;
		phils[i].meals_eaten = 0;
		phils[i].state = UNKNOWN;
		phils[i].left_fork = NULL;
		phils[i].right_fork = NULL;
		phils[i].left_phil = NULL;
		phils[i].right_phil = NULL;
		phils[i].philo = NULL;
		i++;
	}
	return (phils);
}

void	phils_set_forks(t_phil *phils, t_fork *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		phils[i].left_fork = &forks[i];
		phils[i].right_fork = &forks[(i + 1) % count];
		i++;
	}
}

void	phils_set_neighbors(t_phil *phils, int count)
{
	int	right_phil_index;
	int	left_phil_index;
	int	i;

	i = 0;
	while (i < count)
	{
		left_phil_index = (i - 1 + count) % count;
		right_phil_index = (i + 1) % count;
		phils[i].left_phil = &phils[left_phil_index];
		phils[i].right_phil = &phils[right_phil_index];
		i++;
	}
}

void	phils_set_philo(t_phil *phils, t_philo *philo, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		phils[i].philo = philo;
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
			pthread_mutex_destroy(&((*phils)[i].mutex_state));
			pthread_mutex_destroy(&((*phils)[i].mutex_last_meal_time));
			(*phils)[i].left_fork = NULL;
			(*phils)[i].right_fork = NULL;
			(*phils)[i].philo = NULL;
			i++;
		}
		free(*phils);
		*phils = NULL;
	}
}
