/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:30:54 by kmykhail          #+#    #+#             */
/*   Updated: 2023/03/15 19:30:56 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t n)
{
	const unsigned char	*s;
	unsigned char		c;

	s = (const unsigned char *)str;
	c = (unsigned char)chr;
	while (n--)
	{
		if (*s == c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
