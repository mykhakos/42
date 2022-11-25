
#include <stdlib.h>

ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}

char *ft_strdup(char *src)
{
    int src_len;
    int i;
    char *dest;

    src_len = ft_strlen(src) + 1;
    if (src_len == 1)
    {
        return (0);
    }
    dest = (char *)(malloc(src_len * sizeof(char)));
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}