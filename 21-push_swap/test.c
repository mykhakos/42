#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void *square_arr(int **arr, int arr_len)
{
    int i;

    i = 0;
    while (i < arr_len)
    {
        //arr[i] = arr[i] * arr[i];
        (*arr)++;
        i++;
    }
}

void *print_arr(int *arr, int arr_len)
{
    int i;

    i = 0;
    while (i < arr_len)
    {
        printf("%i ", arr[i]);
        i++;
    }
    printf("%s", "\n");
}

int get_ptr_cpy(int *arr)

int main(int argc, char *argv[])
{
    int *arr;
    int arr_len;
    int i;

    arr_len = 3;
    arr = malloc(sizeof(int) * arr_len);
    if (!arr)
        return (1);
    i = 0;
    while (i < arr_len)
    {
        arr[i] = i + 1;
        i++;
    }
    print_arr(arr, arr_len);
    square_arr(&arr, arr_len);
    print_arr(arr, arr_len);
}