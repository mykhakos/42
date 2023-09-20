/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:55:39 by kmykhail          #+#    #+#             */
/*   Updated: 2023/03/15 17:56:42 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	bytes;

	if (num == 0 || size == 0)
		return (malloc(0));
	bytes = num * size;
	if (bytes / size != num)
		return (NULL);
	ptr = malloc(num * size);
	if (ptr != NULL)
		ft_bzero(ptr, num * size);
	return (ptr);
}
