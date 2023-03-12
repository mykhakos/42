/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:41:03 by kmykhail          #+#    #+#             */
/*   Updated: 2022/11/17 18:41:09 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	fr_write(char ones, char doz, char hundr)
{
	write(1, &hundr, 1);
	write(1, &doz, 1);
	write(1, &ones, 1);
	if (ones != '9' || doz != '8' || hundr != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	hundr;
	char	doz;
	char	ones;

	hundr = '0';
	doz = '1';
	ones = '2';
	while (hundr <= '7')
	{
		fr_write(ones, doz, hundr);
		ones += 1;
		if (ones > '9')
		{
			doz += 1;
			if (doz > '8')
			{
				hundr += 1;
				doz = hundr + 1;
			}
			ones = doz + 1;
		}
	}
}
