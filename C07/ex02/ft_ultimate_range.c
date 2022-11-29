#include <stdlib.h>
#include <stdio.h>

/*
int	ft_ultimate_range(int **range, int min, int max)
{
    int		i;
	int		len;
	int		*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	buffer = malloc(len * sizeof(int));
	if (!buffer)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		buffer[i] = min + i;
		i++;
	}
    *range = buffer;
	return (len);
}
*/

int ft_ultimate_range(int **range, int min, int max)
{
    int len;
    int i;

    if (min >= max)
    {
        range = 0;
        return (0);
    }
    len = max - min;
    //range = malloc(sizeof(int*));
    //*range[0] = malloc(len * sizeof(int));
    *range = malloc(len * sizeof(int));
    i = 0;
    while (i < len)
    {
        //*range[i] = min + i;
        range[0][i] = min + i;
        i++;
    }
    return (len);
}

int main()
{
    //int **arr
    int *arr;
    int min = 0;
    int max = 3;
    int len;
    int i = 0;
    
    //len = ft_ultimate_range(arr, min, max);
    len = ft_ultimate_range(&arr, min, max);
    while(i < len)
    {
        //printf("%i, ", arr[0][i]);
        printf("%i, ", arr[i]);
        i++;
    }
    return(0);
}
