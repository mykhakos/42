/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:43 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/22 21:16:33 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_og.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_modif;
	unsigned int	s_len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	s_modif = malloc((s_len + 1) * sizeof(char));
	if (!s_modif)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		s_modif[i] = f(i, s[i]);
		i++;
	}
	s_modif[i] = '\0';
	return (s_modif);
}
