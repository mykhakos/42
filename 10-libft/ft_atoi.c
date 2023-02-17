/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:11:03 by kmykhail          #+#    #+#             */
/*   Updated: 2023/02/16 18:11:06 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	is_num(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if ((c == '+') || (c == '-'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

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


#include <stdio.h>
int main()
{
	char num[] = " ---+--+-2147483648";
	printf("%i\n", ft_atoi(num));
	return 0;
}