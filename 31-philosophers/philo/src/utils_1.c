/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:47:02 by kmykhail          #+#    #+#             */
/*   Updated: 2024/01/09 17:33:47 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

static int	is_num(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

static int	is_sign(char c)
{
	if ((c == '+') || (c == '-'))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (is_space(*str))
		str++;
	if (is_sign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_num(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
