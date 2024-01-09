/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:14:56 by kmykhail          #+#    #+#             */
/*   Updated: 2024/01/09 16:44:36 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_fork	*forks_init(int count)
{
	int		i;
	t_fork	*forks;

	forks = malloc(sizeof(t_fork) * count);
	if (forks == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&(forks[i].mutex), NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&(forks[i].mutex));
			}
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void	forks_free(t_fork **forks, int count)
{
	int	i;

	if (forks != NULL && *forks != NULL)
	{
		i = 0;
		while (i < count)
		{
			pthread_mutex_destroy(&((*forks)[i].mutex));
			i++;
		}
		free(*forks);
		*forks = NULL;
	}
}
