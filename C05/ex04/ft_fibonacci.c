int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    if (index == 0)
        return (0);
    if (index == 1)
        return (1);
    //if (index > 1)
    return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

#include <stdio.h>
int main()
{
	int idx = -9;
	printf("%i\n", ft_fibonacci(idx));
}