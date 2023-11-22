/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:50:08 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/22 21:16:33 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_og.h"

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
