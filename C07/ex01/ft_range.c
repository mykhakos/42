
#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int *range;
    int len;
    int i;

    if (start >= end)
    {
        return (NULL);
    }
    len = end - start;
    range = malloc(len * sizeof(int));
    i = 0;
    while (i < len)
    {
        range[i] = start + i;
        i++;
    }
    return (range);
}


int main()
{

    int start = 0;
    int end = 3;
    int *arr;

    arr = ft_range(start, end);
    int size = end - start;
    int i = 0;
    while(i < size)
    {
        printf("%i, ", arr[i]);
        i++;
    }
    return(0);
}