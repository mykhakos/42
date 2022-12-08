/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:13:57 by kmykhail          #+#    #+#             */
/*   Updated: 2022/12/05 16:13:58 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_totlen(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	if (len != 0)
		len += ft_strlen(sep) * (size - 1);
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	len = ft_totlen(size, strs, sep);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i < size - 1)
			str = ft_strcat(str, sep);
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int main()
{
	char *strs[] = {"g", "woeowowowowowowow", "1234"};
	char *strjoin = ft_strjoin(3, strs, ", ");
	printf("%s\n", strjoin);
}
*/
