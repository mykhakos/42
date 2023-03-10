#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	char *s = NULL;
	while (*str != '\0')
	{
		if (*str == c)
			s = (char *)str;
		str++;
	}
	if (*str == c)
		s = (char *)str;
	return s;
}