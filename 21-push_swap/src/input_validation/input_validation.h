#ifndef INPUT_VALIDATION_INPUT_VALIDATION_H
    #define INPUT_VALIDATION_INPUT_VALIDATION_H

    #include "limits.h"
    #include "../../libft/libft.h"

    void exit_with_error_msg(int exit_code, char *msg);
    int is_number(char *str);
    int is_int(char *nbr);
    int has_dup(int *arr, int arr_len);

#endif