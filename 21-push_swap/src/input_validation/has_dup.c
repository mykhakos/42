#include "input_validation.h"


int has_dup(int *arr, int arr_len)
{
    int i;
    int j;

    i = 0;
    while (i < arr_len)
    {
        j = i + 1;
        while (j < arr_len)
        {
            if (arr[i] == arr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
