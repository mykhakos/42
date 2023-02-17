/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:20:19 by kmykhail          #+#    #+#             */
/*   Updated: 2023/02/13 14:20:20 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1) <-----s----->                start at end of s
                 <-----d----->

2) <-----s----->                start at end of s
            <-----d----->

3) <-----s----->                no action
   <-----d----->

4)          <-----s----->       start at beginning of s
   <-----d----->

5)               <-----s----->  start at beginning of s
   <-----d----->
*/

void *ft_memmove(void* dest, const void* src, size_t n)
{
	char* d = (char*)dest;
	const char* s = (const char*)src;

	if (d < n)
    {
        s += n;
        d += n;
		while (n--)
			*(--d) = *(--s);
	}
	else if (d > n)
	{
		while (n--)
			*(d++) = *(s++);
	}
    return (dest);
}
