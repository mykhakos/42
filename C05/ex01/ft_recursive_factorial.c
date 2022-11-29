int ft_recursive_factorial(int nb)
{
	int	res;

	if (nb < 0)
	{
		return (0);
	}
    res = 1;
	if (nb > 0)
    {
        res = nb * ft_recursive_factorial(nb - 1);
    }
    return (res);
}
	    
#include <stdio.h>
int main()
{
	int num = 5;
	printf("%i\n", ft_recursive_factorial(num));
}

