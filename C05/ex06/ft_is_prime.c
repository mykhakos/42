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

#include <stdio.h>
int main()
{
	int num = 2147483647;
	printf("%i\n", ft_is_prime(num));
}