int ft_sqrt(int nb)
{
    int sq_root;

    if (nb < 0)
    {
        return (0);
    }
    sq_root = 0;
    while (sq_root * sq_root < nb)
    {
        sq_root += 1;
    }
    if (sq_root * sq_root > nb)
    {
        return (0);
    }
    return (sq_root);
}

#include <stdio.h>
int main()
{
	int num = 26;
	printf("%i\n", ft_sqrt(num));
}