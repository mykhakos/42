/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:49:04 by kmykhail          #+#    #+#             */
/*   Updated: 2023/04/01 14:49:05 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/utils.h"

static void	choose_put_func(char form_specif, va_list args, size_t *counter)
{
	if (form_specif == 'c')
		ft_put_char(va_arg(args, int), counter);
	else if (form_specif == 's')
		ft_put_str(va_arg(args, char *), counter);
	else if (form_specif == 'p')
		ft_put_ptr(va_arg(args, void *), counter);
	else if (form_specif == 'd' || form_specif == 'i')
		ft_put_int_as_dec(va_arg(args, int), counter);
	else if (form_specif == 'u')
		ft_put_uint_as_dec(va_arg(args, unsigned int), counter);
	else if (form_specif == 'x')
		ft_put_uint_as_hex(va_arg(args, unsigned int), 0, counter);
	else if (form_specif == 'X')
		ft_put_uint_as_hex(va_arg(args, unsigned int), 1, counter);
	else if (form_specif == '%')
		ft_put_char('%', counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	counter;
	size_t	i;

	va_start(args, format);
	counter = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			choose_put_func(format[i + 1], args, &counter);
			i++;
		}
		else
		{
			ft_put_char(format[i], &counter);
		}
		i++;
	}
	va_end(args);
	return (counter);
}
