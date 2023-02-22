/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:24:23 by kmykhail          #+#    #+#             */
/*   Updated: 2022/02/21 20:24:32 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putstr_fd(ft_itoa(INT_MIN), fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

/*
int main(void)
{
    int fd = 1; // Standard output
    ft_putnbr_fd(42, fd); // Should print "42" to the console
	ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-42, fd); // Should print "-42" to the console
	ft_putchar_fd('\n', fd);
    ft_putnbr_fd(0, fd); // Should print "0" to the console
	ft_putchar_fd('\n', fd);
    ft_putnbr_fd(2147483647, fd); // Should print "2147483647" to the console
	ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-2147483648, fd); // Should print "-2147483648" to the console
	ft_putchar_fd('\n', fd);
    return (0);
}
*/