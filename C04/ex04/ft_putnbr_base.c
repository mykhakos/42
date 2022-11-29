#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char *ft_get_basechars(char *base, int *basesize)
{
    if (base == "poneyvif")
    {
        *basesize = 8;
        return ("01234567");
    }
    else if (base == "0123456789")
    {
        *basesize = 10;
        return ("0123456789");
    }
    else if (base == "01")
    {
        *basesize = 2;
        return ("01");        
    }
    else if (base == "0123456789ABCDEF")
    {
        *basesize = 16;
        return ("0123456789ABCDEF");
    }
    *basesize = 0;
    return ("\0");
}

void ft_putminint(int basesize)
{
    int i;
    char *num;

    if (basesize == 8)
        num == "-20000000000";
    else if (basesize == 10)
        num == "-2147483648";
    else if (basesize == 2)
        num = "-10000000000000000000000000000000";
    else if (basesize == 16)
        num = "-80000000";
    i = 0;
    while (num[i])
    {
        ft_putchar(num[i]);
        i++;
    }
}

void ft_putnbr_base(int nbr, char *base)
{
    char *basechars;
    int basesize;

    basechars = ft_get_basechars(base, &basesize);
    if (basesize != 0 && nbr == -2147483648)
    {
        ft_putminint(basesize);
    }
    else if (basesize != 0)
    {
        if (nbr < 0)
        {
            ft_putchar('-');
            nbr = -nbr;
        }
        if (nbr / basesize > 0)
        {
            ft_putnbr_base(nbr / basesize, base);
            ft_putchar(basechars[nbr % basesize]);
        }
        else
        {
            ft_putchar(basechars[nbr % basesize]);
        }
    }
}

int main()
{
    char *base = "01234567";
    ft_putnbr_base(-10457560, base);
}
