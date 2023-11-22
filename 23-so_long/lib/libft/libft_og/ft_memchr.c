/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:30:54 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/22 21:16:33 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_og.h"

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
