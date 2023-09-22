/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:50:43 by kmykhail          #+#    #+#             */
/*   Updated: 2023/03/16 18:50:45 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = (unsigned int)ft_strlen(s);
	if (s_len == 0 || len == 0 || start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		substr = malloc((s_len - start + 1) * sizeof(char));
	else
		substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != 0)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
