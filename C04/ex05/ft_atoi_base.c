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

int is_space(char c)
{
    if (c == ' ') //replace
        return (1);
    return (0);    
}

int is_sign(char c)
{
    if (c == '-' || c == '+')
        return (1);
    return (0);
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);    
}

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}

int ft_to_decimal(char c, char *basechars)
{
    int num;

    num = 0;
    while (basechars[num])
    {
        if (c == basechars[num])
            return (num);
        num++;
    }
    return (-1);
}


int ft_atoi_base(char *str, char *base)
{
    int sign;
    int num;
    int num_tmp;
    char *basechars;
    int basesize;
    
    num = 0;
    sign = 1;
    basechars = ft_get_basechars(base, &basesize);
    while (is_space(*str))
    {
        str++;
    }
    while (is_sign(*str))
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (is_num(*str))
    {
        num_tmp = ft_to_decimal(*str, basechars);
        
        if (num_tmp == -1)
            return(0);
        num = basesize * num + (*str - '0');
        //printf("%d\n", num);
        str++;
    }
    return (num * sign);
}


// Driver Code
int main()
{
    char *str = "  +-123";
    char *base = "0123456789ABCDEF";
   
    // Functional Code
    int val = ft_atoi_base(str, base);
    printf("%d ", val);
    return 0;
}