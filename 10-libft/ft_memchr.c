#include "libft.h"

void *ft_memchr(const void *str, int chr, size_t n)
{
    const unsigned char* s = (const unsigned char*)str;
    unsigned char c = (unsigned char)chr;
	while (n--)
	{
		if (*s == c)
			return (void *)s;
		s++;
	}
	return NULL;
}