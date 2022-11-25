#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *arr)
{
    int len;

    len = 0;
    while (arr[len])
    {
        len++;
    }
    return (len);
}

int next_idx(char c, char *str, int start_idx)
{
    while (str[start_idx])
    {
        if (c == str[start_idx])
        {
            return (start_idx + 1);
        }
        start_idx++;
    }
    return (0);
}

int found_wdmatch(char **arrs)
{
    int i;
    int j;

    if (ft_strlen(arrs[1]) > ft_strlen(arrs[2]))
    {
        return (0);
    }
    i = 0;
    j = 0;
    while (arrs[1][i])
    {
        j = next_idx(arrs[1][i], arrs[2], j);
        if (j == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

void ft_putstr(char *arr)
{
    int i;

    i = 0;
    while(arr[i])
    {
        write(1, &arr[i], 1);
        i++;
    }
}

int main(int ac, char *av[])
{
    if (ac == 3 && found_wdmatch(av))
    {
        ft_putstr(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}