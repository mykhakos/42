#include "libft.h"


size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_modif;
	unsigned int	s_len;
	unsigned int	i;
	
	if (!s || !f)
		return NULL;	
	s_len = ft_strlen(s);
	s_modif = malloc((s_len + 1) * sizeof(char));
	if (!s_modif)
		return NULL;
	i = 0;
	while (i < s_len)
	{
		s_modif[i] = f(i, s[i]);
		i++;
	}
	s_modif[i] = '\0';
	return s_modif;
}

/*
// Example function to apply to each character of the string
char to_uppercase(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    else
        return c;
}

#include <stdio.h>

int main()
{
    char *str = "Hello, world!";
    char *result = ft_strmapi(str, to_uppercase);
    char *expected = "HELLO, WORLD!";

    // Check that the result is correct
    if (strcmp(result, expected) != 0)
    {
        printf("Test failed: expected '%s', but got '%s'\n", expected, result);
    }
    else
    {
        printf("Test passed!\n");
    }

    // Free the memory allocated by ft_strmapi
    free(result);

    return 0;
}
*/