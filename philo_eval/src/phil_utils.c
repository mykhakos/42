/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:46:19 by kmykhail          #+#    #+#             */
/*   Updated: 2024/01/09 16:46:25 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	phil_log(t_phil *phil, char *msg, const char *color_code)
{
	long	timestamp_now;
	long	time_diff;

	timestamp_now = get_current_time_ms(&(phil->philo));
	time_diff = timestamp_now - phil->philo->timestamp_simstart;
	if (!color_code)
		color_code = COLOR_DEFAULT;
	pthread_mutex_lock(&(phil->philo->mutex_log));
	printf("%s%04ld %i %s%s\n", color_code, time_diff, phil->id, msg,
		COLOR_DEFAULT);
	pthread_mutex_unlock(&(phil->philo->mutex_log));
}

t_phil_state	phil_get_state(t_phil *phil)
{
	t_phil_state	state;

	pthread_mutex_lock(&(phil->mutex_state));
	state = phil->state;
	pthread_mutex_unlock(&(phil->mutex_state));
	return (state);
}

void	phil_set_state(t_phil *phil, t_phil_state state)
{
	pthread_mutex_lock(&(phil->mutex_state));
	phil->state = state;
	pthread_mutex_unlock(&(phil->mutex_state));
}

long	phil_get_last_meal_time(t_phil *phil)
{
	long	last_meal_time;

	pthread_mutex_lock(&(phil->mutex_last_meal_time));
	last_meal_time = phil->last_meal_time;
	pthread_mutex_unlock(&(phil->mutex_last_meal_time));
	return (last_meal_time);
}

void	phil_set_last_meal_time(t_phil *phil, long timestamp)
{
	pthread_mutex_lock(&(phil->mutex_last_meal_time));
	phil->last_meal_time = timestamp;
	pthread_mutex_unlock(&(phil->mutex_last_meal_time));
}
