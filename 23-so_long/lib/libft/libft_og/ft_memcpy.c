/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:20:19 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/22 21:16:33 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_og.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src && n)
		return (NULL);
	while (n--)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
