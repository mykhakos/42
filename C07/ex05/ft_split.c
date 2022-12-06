#include <stdlib.h>
#include <stdio.h>

int ft_is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
        charset++;
	}
	return (0);
}

int ft_wordlen(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && !ft_is_sep(str[len], charset))
		len++;
	return (len);
}

int ft_wordcount(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
    {
        str = str + ft_wordlen(str, charset);
        while (ft_is_sep(*str, charset))
            str++;
        count++;
    }
	return (count);
}

char **ft_split(char *str, char *charset)
{
    char **arr;
    int word_len;
    int i;
    int j;

    arr = malloc((ft_wordcount(str, charset) + 1) * sizeof(char *));
    i = 0;
	while (*str)
    {
        j = 0;
        word_len = ft_wordlen(str, charset);
        arr[i] = malloc((word_len + 1) * sizeof(char));
        while (j < word_len)
            arr[i][j++] = *str++;
        arr[i][j] = '\0';
        i += 1;
        while (ft_is_sep(*str, charset))
            str++;
    }
    arr[i] = malloc(sizeof(char));
    arr[i][0] = '\0';
    return (arr);
}
