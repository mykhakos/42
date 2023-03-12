/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:21:01 by kmykhail          #+#    #+#             */
/*   Updated: 2022/11/30 15:21:13 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_check_base(char *base, int *basesize)
{
	int	i;

	*basesize = ft_strlen(base);
	if (*basesize < 2)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	i = 0;
	while (base[i + 1])
	{
		if (base[i] == base[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				err;
	int				basesize;
	unsigned int	nbr_tmp;

	err = ft_check_base(base, &basesize);
	if (err == 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr_tmp = -nbr;
		}
		else
			nbr_tmp = nbr;
		if (nbr_tmp / basesize > 0)
		{
			ft_putnbr_base(nbr_tmp / basesize, base);
			ft_putchar(base[nbr_tmp % basesize]);
		}
		else
		{
			ft_putchar(base[nbr_tmp % basesize]);
		}
	}
}
