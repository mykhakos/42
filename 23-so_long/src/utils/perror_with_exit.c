# include "../../include/so_long.h"


void perror_with_exit(int exit_code, char *err_msg)
{
    ft_printf("%s (%i)\n", err_msg, exit_code);
    //exit(exit_code);       
}