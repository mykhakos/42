/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:27:26 by kmykhail          #+#    #+#             */
/*   Updated: 2023/04/01 15:27:29 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_put_char(char c, size_t *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

void	ft_put_str(char *s, size_t *counter)
{
	if (s != NULL)
	{
		while (*s != '\0')
			ft_put_char(*s++, counter);
	}
	else
	{
		ft_put_str("(null)", counter);
	}
}
