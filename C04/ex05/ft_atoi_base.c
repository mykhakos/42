/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:57:15 by kmykhail          #+#    #+#             */
/*   Updated: 2022/11/30 17:57:17 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_check_base(char *base, int *basesize)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	if (i < 2)
		return (1);
	*basesize = i;
	i = 0;
	while (base[i + 1])
	{
		if (base[i] == base[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_to_decimal(char c, char *base)
{
	int	num;

	num = 0;
	while (base[num])
	{
		if (c == base[num])
			return (num);
		num++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	num;
	int	num_tmp;
	int	basesize;

	num = 0;
	sign = 1;
	if (ft_check_base(base, &basesize))
		return (0);
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (ft_to_decimal(*str, base) == -1)
			break ;
		num = basesize * num + ft_to_decimal(*str, base);
		str++;
	}
	return (num * sign);
}
