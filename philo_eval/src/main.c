/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:47:32 by kmykhail          #+#    #+#             */
/*   Updated: 2024/01/09 17:46:33 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	philo_set_time_durations(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atol(argv[ARGV_IDX_T_DIE]);
	if (philo->time_to_die < 0)
	{
		printf("Time to die must be non-negative.\n");
		return (1);
	}
	philo->time_to_eat = ft_atol(argv[ARGV_IDX_T_EAT]);
	if (philo->time_to_eat < 0)
	{
		printf("Time to eat must be non-negative.\n");
		return (1);
	}
	philo->time_to_sleep = ft_atol(argv[ARGV_IDX_T_SLEEP]);
	if (philo->time_to_sleep < 0)
	{
		printf("Time to sleep must be non-negative.\n");
		return (1);
	}
	return (0);
}

static int	philo_set_from_argv(t_philo *philo, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of args (expected 4 or 5, got %i).\n", argc);
		return (1);
	}
	philo->number_of_phils = (int)ft_atol(argv[ARGV_IDX_PHIL_COUNT]);
	if (philo->number_of_phils < 1)
	{
		printf("Number of philosophers must be positive.\n");
		return (1);
	}
	if (philo_set_time_durations(philo, argv) != 0)
		return (1);
	if (argc == 6)
	{
		philo->number_of_meals = (int)ft_atol(argv[ARGV_IDX_MEAL_COUNT]);
		if (philo->number_of_meals < 0)
		{
			printf("Number of meals must be non-negative.\n");
			return (1);
		}
		return (0);
	}
	philo->number_of_meals = -1;
	return (0);
}

static int	philo_init_and_set_params(t_philo *philo, int argc, char **argv)
{
	long	timestamp_simstart;
	int		i;

	if (philo_set_from_argv(philo, argc, argv) != 0)
		return (1);
	if (philo_init_and_set_phils_and_forks(philo, philo->number_of_phils) != 0)
		return (1);
	timestamp_simstart = get_current_time_ms(&philo);
	philo->timestamp_simstart = timestamp_simstart;
	i = 0;
	while (i < philo->number_of_phils)
	{
		philo->phils[i].last_meal_time = timestamp_simstart;
		i++;
	}
	return (0);
}

static void	run_routines(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->number_of_phils)
	{
		pthread_create(&(philo->phils[i].thread), NULL, phil_routine,
			(void *)&(philo->phils[i]));
		i++;
	}
	i = 0;
	while (i < philo->number_of_phils)
	{
		pthread_join(philo->phils[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = philo_init();
	if (!philo)
		return (1);
	if (philo_init_and_set_params(philo, argc, argv) != 0)
	{
		philo_free(&philo);
		return (1);
	}
	run_routines(philo);
	philo_free(&philo);
	return (0);
}
