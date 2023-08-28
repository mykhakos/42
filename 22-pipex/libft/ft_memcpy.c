/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:20:19 by kmykhail          #+#    #+#             */
/*   Updated: 2023/02/13 14:20:20 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void* dest, const void* src, size_t n)
{
    char* d = (char*)dest;
    const char* s = (const char*)src;

    while (n--)
        *d++ = *s++;
    return (dest);
}
