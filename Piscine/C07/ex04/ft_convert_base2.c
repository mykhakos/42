/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:14:13 by kmykhail          #+#    #+#             */
/*   Updated: 2022/12/05 16:14:15 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
{
	int	i;
	int	basesize;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	if (i < 2)
		return (1);
	basesize = i;
	i = 0;
	while (base[i + 1])
	{
		if (base[i] == base[i + 1])
			return (1);
		i++;
	}
	return (basesize);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
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
	int	basesize;

	basesize = ft_check_base(base);
	num = 0;
	sign = 1;
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
