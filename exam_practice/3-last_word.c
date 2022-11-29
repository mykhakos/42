#include <unistd.h>

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

void ft_putstr(char *arr, int start_idx, int end_idx)
{
    while (arr[start_idx] && (start_idx <= end_idx))
    {
        write(1, &arr[start_idx], 1);
        start_idx++;
    }
}

int is_delim(char c)
{
    if (c == 32 || c == 9)
    {
        return (1);
    }
    return (0);
}

int find_last(char *str)
{
    int start_idx;
    int end_idx;
    int i;

    if (ft_strlen(str) == 0)
        return (1);
    start_idx = 0;
    end_idx = ft_strlen(str) - 1;
    while (is_delim(str[end_idx]))
    {
        end_idx--;
    }
    i = 0;
    while(str[i])
    {
        if ((i == 0 || is_delim(str[i])) && i <= end_idx)
        {
            start_idx = i + 1;
        }
        i++;
    }
    ft_putstr(str, start_idx, end_idx);
    return (0);
}

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        find_last(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}