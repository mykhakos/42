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
	int				id;

	phils = malloc(sizeof(t_phil) * count);
	if (phils == NULL)
		return (NULL);
	id = 0;
	while (id < count)
	{
		phils[id].id = id + 1;
		phils[id].last_meal_time = get_current_time_ms(NULL);
		phils[id].meals_eaten = 0;
		phils[id].state = UNKNOWN;
		phils[id].left_fork = NULL;
		phils[id].right_fork = NULL;
		phils[id].philo = NULL;
		id++;
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
			(*phils)[i].left_fork = NULL;
			(*phils)[i].right_fork = NULL;
			(*phils)[i].philo = NULL;
			i++;
		}
		free(*phils);
		*phils = NULL;
	}
}
