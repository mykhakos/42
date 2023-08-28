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
	char* dst_ptr = (char*)dest;
	const char* src_ptr = (const char*)src;

	if (dst_ptr < src_ptr)
    {
        src_ptr += n;
        dst_ptr += n;
		while (n--)
			*(--dst_ptr) = *(--src_ptr);
	}
	else if (dst_ptr > src_ptr)
	{
		while (n--)
			*(dst_ptr++) = *(src_ptr++);
	}
    return (dest);
}
