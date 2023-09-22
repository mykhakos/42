/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:53:01 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/22 19:44:41 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

long long	ft_atol(const char *str)
{
	long long	sign;
	long long	num;

	sign = 1;
	num = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
	{
		str++;
	}
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

int	is_int(char *nbr)
{
	long long	nbr_converted;

	nbr_converted = ft_atol(nbr);
	if (nbr_converted < INT_MIN || nbr_converted > INT_MAX)
	{
		return (0);
	}
	return (1);
}
