
int ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
	{
		return (0);
	}
	res = 1;
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

#include <stdio.h>
int main()
{
	int num = -1;
	printf("%i\n", ft_iterative_factorial(num));
}



