/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:47:02 by kmykhail          #+#    #+#             */
/*   Updated: 2024/01/09 16:51:46 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_current_time_ms(t_philo **philo)
{
	struct timeval	tv;
	int				ret;

	ret = gettimeofday(&tv, NULL);
	if (ret != 0)
	{
		if (philo != NULL && *philo != NULL)
		{
			philo_free(philo);
		}
		perror("gettimeofday");
		exit(EXIT_FAILURE);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	mutex_safeinit(pthread_mutex_t *mutex, void **free_on_error)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		if (free_on_error != NULL && *free_on_error != NULL)
		{
			free(*free_on_error);
			*free_on_error = NULL;
		}
		return (1);
	}
	return (0);
}
