#include "input_validation.h"


void exit_with_error_msg(int exit_code, char *msg)
{
    ft_putendl_fd(msg, STDERR_FILENO);
    exit(exit_code);
}
