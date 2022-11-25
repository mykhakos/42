
#include <stdlib.h>
#include <stdio.h>

int ft_abs(int i)
{
    if (i < 0)
    {
        return (-i);
    }
    return (i);
}

int     *ft_range(int start, int end)
{
    int *range;
    int len;
    int i;

    len = ft_abs(start - end) + 1;
    range = (int *)malloc(len * sizeof(int));
    i = 0;
    while (i < len)
    {
        range[i] = start;
        if (start < end)
        {
            start++;  
        }
        else
        {
            start--;    
        }
        i++;
    }
    return (range);
}


int main()
{

    int start = 0;
    int end = 0;
    int *arr;

    arr = ft_range(start, end);
    int size = ft_abs(end - start)+1;
    int i = 0;
    while(i < size)
    {
        printf("%i, ", arr[i]);
        i++;
    }
    return(0);
}