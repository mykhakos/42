int ft_iterative_power(int nb, int power)
{
    int res;

    if (power < 0)
    {
        return (0);
    }
    if (nb == 0 && power == 0)
    {
        return (1);
    }
    res = 1;
    while (power > 0)
    {
        res *= nb;
        power--;
    }
    return (res);
}

#include <stdio.h>
int main()
{
	int num = 3;
    int pow = 3;
	printf("%i\n", ft_iterative_power(num, pow));
}