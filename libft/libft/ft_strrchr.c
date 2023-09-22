/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:50:08 by kmykhail          #+#    #+#             */
/*   Updated: 2023/03/16 18:50:10 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (NULL);
	while (*str != '\0')
	{
		if (*str == (char)c)
			s = (char *)str;
		str++;
	}
	if (*str == c)
		s = (char *)str;
	return (s);
}
