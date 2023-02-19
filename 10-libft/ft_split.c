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

size_t	ft_wordlen(const char *str, const char sep)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != sep)
		len++;
	return (len);
}

size_t	ft_wordcount(const char *str, const char sep)
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

char	*ft_wordcpy(const char *str, const char sep)
{
	char	*word;
	size_t	word_len;
	size_t	i;

	i = 0;
	word_len = ft_wordlen(str, sep);
	word = malloc((word_len + 1) * sizeof(char));
	if (!word)
		return NULL;
	while (i < word_len)
		word[i++] = *str++;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char sep)
{
	char	**arr;
	size_t	word_count;
	size_t	i;

	word_count = ft_wordcount(str, sep);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return NULL;
	i = 0;
	while (i < word_count)
	{
		while (*str == sep)
			str++;
		arr[i++] = ft_wordcpy(str, sep);
		str += ft_wordlen(str, sep);
	}
	arr[i] = NULL;
	return (arr);
}

/*
#include <stdio.h>
int main()
{
	char *str = "HlgPB01cB miPyxzOGWvAZ1X9bsm3M0OXD6CRNTFrDly     XrN";
	char sep = 'y';
	//printf("%p\n", str);
	printf("%s\n", ft_split(str, sep)[0]);
	printf("%s\n", ft_split(str, sep)[1]);
	printf("%s\n", ft_split(str, sep)[2]);
	//printf("%s\n", ft_split(str, sep)[3]);
	//printf("%p\n", str);
	return 0;
}
*/
