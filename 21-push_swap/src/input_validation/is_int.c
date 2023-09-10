#include "input_validation.h"


long	ft_atol(const char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
    if (*str == '+')
    {
        str++;
    }
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while ((*str > '0') && (*str <= '9'))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}


int is_int(char *nbr)
{
    long nbr_converted;

    nbr_converted = ft_atol(nbr);
    if (nbr_converted < INT_MIN || nbr_converted > INT_MAX)
        return (0);
    return (1);
}
