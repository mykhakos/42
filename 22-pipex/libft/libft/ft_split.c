/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/06 22:39:50 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/02/19 22:39:51 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *str, const char sep)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != sep)
		len++;
	return (len);
}

static size_t	ft_wordcount(const char *str, const char sep)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str != sep && (*(str + 1) == sep || *(str + 1) == '\0'))
			count++;
		str++;
	}
	return (count);
}

static char	*ft_wordcpy(const char *str, const char sep)
{
	char	*word;
	size_t	word_len;
	size_t	i;

	i = 0;
	word_len = ft_wordlen(str, sep);
	word = malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < word_len)
		word[i++] = *str++;
	word[i] = '\0';
	return (word);
}

static char	**free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (arr);
}

char	**ft_split(char const *str, char sep)
{
	char	**arr;
	size_t	word_count;
	size_t	i;

	if (!str)
		return (NULL);
	word_count = ft_wordcount(str, sep);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*str == sep)
			str++;
		arr[i++] = ft_wordcpy(str, sep);
		if (!arr[i - 1])
			return (free_array(arr));
		str += ft_wordlen(str, sep);
	}
	arr[i] = NULL;
	return (arr);
}
