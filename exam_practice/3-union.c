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
        arr[i] = '\0';
        i++;
    }
}

void find_union(char **arrs, char *mem)
{
    int i;
    int j;
    int k;

    i = 1;
    k = 0;
    while (i < 3)
    {
        j = 0;
        while (arrs[i][j])
        {
            if (!is_in(arrs[i][j], mem))
            {
                write(1, &arrs[i][j], 1);
                mem[k] = arrs[i][j];
                k++;
            }
            j++;
        }
        i++;
    }
}

int main(int ac, char *av[])
{
    int i;
    int j;
    int k;
    char mem[65536];

    if (ac == 3)
    {
        fill_with_zeros(mem, 65536);
        find_union(av, mem);
    }
    write(1, "\n", 1);
    return (0);
}