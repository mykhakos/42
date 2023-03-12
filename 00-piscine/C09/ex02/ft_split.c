/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kmykhail <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/06 22:39:50 by kmykhail		  #+#	#+#			 */
/*   Updated: 2022/12/06 22:39:51 by kmykhail		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	if (c == '\0')
		return (1);
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_wordlen(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && !ft_is_sep(str[len], charset))
		len++;
	return (len);
}

int	ft_wordcount(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], charset) && ft_is_sep(str[i + 1], charset))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		word_len;
	int		word_count;
	int		i;
	int		j;

	word_count = ft_wordcount(str, charset);
	arr = malloc((word_count + 1) * sizeof(char *));
	i = 0;
	while (*str && i < word_count)
	{
		while (ft_is_sep(*str, charset))
			str++;
		j = 0;
		word_len = ft_wordlen(str, charset);
		arr[i] = malloc((word_len + 1) * sizeof(char));
		while (j < word_len)
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
		i += 1;
	}
	arr[i] = 0;
	return (arr);
}

/*
#include <stdio.h>
int main()
{
	char *str = "HlgPB01cB miPyxzOGWvAZ1X9bsm3M0OXD6CRNTFrDly     XrN";
	char *sep = "Ic4w";
	//printf("%p\n", str);
	printf("%s\n", ft_split(str, sep)[0]);
	printf("%s\n", ft_split(str, sep)[1]);
	printf("%s\n", ft_split(str, sep)[2]);
	//printf("%s\n", ft_split(str, sep)[3]);
	//printf("%p\n", str);
}
*/
