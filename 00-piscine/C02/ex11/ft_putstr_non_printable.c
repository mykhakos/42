/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:24:32 by kmykhail          #+#    #+#             */
/*   Updated: 2022/11/22 20:24:34 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_printable(char c)
{
	write(1, &c, 1);
}

void	write_non_printable(unsigned char c)
{
	char	*hexnums;

	hexnums = "0123456789abcdef";
	write(1, &hexnums[c / 16], 1);
	write(1, &hexnums[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32) || (str[i] > 126))
		{
			write_printable('\\');
			write_non_printable(str[i]);
		}
		else
		{
			write_printable(str[i]);
		}
		i++;
	}
}
