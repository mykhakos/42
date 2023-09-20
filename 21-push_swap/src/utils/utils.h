#ifndef UTILS_UTILS_H
    #define UTILS_UTILS_H

    #include <unistd.h>
    #include <stdlib.h>
    #include "../../libft/libft.h"
    #include "../input_validation/input_validation.h"

    int *argv_to_int(int argc, char **argv);
    void exit_with_error_msg(int exit_code, char *msg);
#endif