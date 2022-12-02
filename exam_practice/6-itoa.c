#include <stdio.h>
#include <stdlib.h>

int ft_numlen(int nbr)
{
    int len;

    len = 0;
    while (nbr / 10 != 0)
    {
        len++;
        nbr /= 10;
    }
    if (nbr < 0)
        len += 1;
    return (len + 1);
}

char *ft_itoa(int nbr)
{
    unsigned int num_tmp;
    char *strnbr;
    int len;

    len = ft_numlen(nbr);
    strnbr = malloc((len + 1) * sizeof(char));
    strnbr[len - 1] =  '\0';
    if (nbr < 0)
    {
        strnbr[0] = '-';
        num_tmp = -nbr;
    }
    else
        num_tmp = nbr;
    while (num_tmp / 10 != 0)
    {
        len--;
        strnbr[len] = num_tmp % 10 + '0';
        num_tmp /= 10;
    }
    strnbr[len - 1] = num_tmp % 10 + '0';
    return (strnbr);
}

int main()
{

    int num = -10345;
    int len = ft_numlen(num);
    printf("%s\n", ft_itoa(num));
}