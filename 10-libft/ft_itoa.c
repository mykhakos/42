
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

/*
#include <stdio.h>
int main(void)
{
    int test_cases[] = {0, INT_MAX, INT_MIN, 7890, -12345};
    int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_test_cases; i++) {
        char *result = ft_itoa(test_cases[i]);
        printf("Input: %d, Result: %s\n", test_cases[i], result);
        //free(result);
    }
    return 0;
}
*/