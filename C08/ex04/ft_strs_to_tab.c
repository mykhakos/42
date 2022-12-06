#include <stdlib.h>
#include "ft_stock_str.h"

int ft_strlen(char *str)
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

    src_len = ft_strlen(src);
    if (src_len == 0)
        return (0);
    dest = malloc((src_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    struct s_stock_str *strs_data;
    int i;

    strs_data = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!strs_data)
		return (NULL);
    i = 0;
    while (i < ac)
    {
        strs_data[i].size = ft_strlen(av[i]);
        strs_data[i].str = av[i];
        strs_data[i].copy = ft_strdup(av[i]);
        i++;
    }
    strs_data[i].str = 0;
    return (strs_data);
}