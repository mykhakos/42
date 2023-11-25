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

t_philosopher	*phils_init(int count)
{
	t_philosopher	*phils;
	int				id;

	phils = malloc(sizeof(t_philosopher) * count);
	if (phils == NULL)
		return (NULL);
	id = 0;
	while (id < count)
	{
		phils[id].id = id;
		phils[id].last_meal_time = 0;
		phils[id].meals_eaten = 0;
		phils[id].left_fork = NULL;
		phils[id].right_fork = NULL;
		phils[id].philo = NULL;
	}
	return (phils);
}

void	phils_set_forks(t_philosopher *phils, t_fork *forks, int count)
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

void	phils_set_philo(t_philosopher *phils, t_philo *philo, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		phils[i].philo = philo;
		i++;
	}
}

void	phils_free(t_philosopher **phils, int count)
{
	int	i;

	i = 0;
	if (phils != NULL && *phils != NULL)
	{
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
