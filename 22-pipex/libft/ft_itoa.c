#include "libft.h"

size_t	ft_numlen(int nbr)
{
	int	len;

	len = 0;
	while (nbr / 10 != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	if (nbr < 0)
		len += 1;
	return (len + 1);
}

char *ft_itoa(int n)
{
	char			*n_str;
	unsigned int	n_tmp;
	size_t			n_len;

	n_len = ft_numlen(n);
	n_str = malloc((n_len + 1) * sizeof(char));
	if (!n_str)
		return NULL;
	n_str[n_len] = '\0';
	if (n < 0)
	{
		n_str[0] = '-';
		n_tmp = -n;
	}
	else
		n_tmp = n;
	while (n_tmp / 10 != 0)
	{
		n_str[--n_len] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	n_str[n_len - 1] = n_tmp % 10 + '0';
	return (n_str);
}
