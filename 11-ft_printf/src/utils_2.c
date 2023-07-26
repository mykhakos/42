/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:27:26 by kmykhail          #+#    #+#             */
/*   Updated: 2023/04/01 15:27:29 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	ft_put_int_as_dec(int n, size_t *counter)
{
	if (n == -2147483648)
	{
		ft_put_str("-2147483648", counter);
		return ;
	}
	if (n < 0)
	{
		ft_put_char('-', counter);
		n = -n;
	}
	if (n / 10 > 0)
	{
		ft_put_int_as_dec(n / 10, counter);
		ft_put_int_as_dec(n % 10, counter);
	}
	else
	{
		ft_put_char(n + '0', counter);
	}
}

void	ft_put_uint_as_dec(unsigned int n, size_t *counter)
{
	if (n / 10 > 0)
	{
		ft_put_uint_as_dec(n / 10, counter);
		ft_put_uint_as_dec(n % 10, counter);
	}
	else
	{
		ft_put_char(n + '0', counter);
	}
}

void	ft_put_uint_as_hex(unsigned long n, int upcase, size_t *counter)
{
	char	*symb;

	if (upcase)
		symb = "0123456789ABCDEF";
	else
		symb = "0123456789abcdef";
	if (n >= 16)
	{
		ft_put_uint_as_hex(n / 16, upcase, counter);
		ft_put_uint_as_hex(n % 16, upcase, counter);
	}
	else
	{
		ft_put_char(symb[n], counter);
	}
}

void	ft_put_ptr(void *ptr, size_t *counter)
{
	if (ptr != 0)
	{
		ft_put_str("0x", counter);
		ft_put_uint_as_hex((unsigned long)ptr, 0, counter);
	}
	else
	{
		ft_put_str("(nil)", counter);
	}
}
