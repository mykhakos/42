/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:26:41 by kmykhail          #+#    #+#             */
/*   Updated: 2023/03/16 19:26:43 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;

	if ((!s1 && !n) || (!s2 && !n))
		return (NULL);
	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char *)s1);
	while (*s1 != '\0' && n >= s2_len)
	{
		if (ft_strncmp(s1, s2, s2_len) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
