#include <unistd.h>
#include <stdio.h>


int is_in(char c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (c == str[i])
        {
            return (1);
        }
        i++;
    }
    return (0);
}

void fill_with_zeros(char *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        arr[i] = 'A';
        i++;
    }
}

int main(int ac, char *av[])
{
    int i;
    int j;
    char chars[4096];

    if (ac == 3)
    {
        fill_with_zeros(chars, 4096);
        i = 0;
        j = 0;
        while (av[1][i])
        {
            if (is_in(av[1][i], av[2]) && !is_in(av[1][i], chars))
            {
                write(1, &av[1][i], 1);
                chars[j] = av[1][i];
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}