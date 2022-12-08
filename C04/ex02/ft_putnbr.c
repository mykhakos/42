/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:24:23 by kmykhail          #+#    #+#             */
/*   Updated: 2022/11/18 20:24:32 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	char_nb;

	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb / 10 > 0)
	{
		ft_putnbr(nb / 10);
		char_nb = nb % 10 + '0';
		nb = nb / 10;
		write(1, &char_nb, 1);
	}
	else
	{
		char_nb = nb % 10 + '0';
		write(1, &char_nb, 1);
	}
}
