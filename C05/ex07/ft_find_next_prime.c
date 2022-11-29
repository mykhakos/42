int ft_is_prime(int nb)
{
    int divider;

    if (nb <= 1)
    {
        return (0);
    }
    divider = 2;
    while (divider < nb)
    {
        if (nb % divider == 0)
        {
            return (0);
        }
        divider++;
    }
    return (1);
}

int ft_find_next_prime(int nb)
{
    int next_prime;

    next_prime = nb;
    while (!ft_is_prime(next_prime))
    {
        next_prime++;
    }
    return (next_prime);
}

#include <stdio.h>
int main()
{
	int num = 2345;
	printf("%i\n", ft_find_next_prime(num));
}