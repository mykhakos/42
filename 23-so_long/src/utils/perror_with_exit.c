# include <stdlib.h>
# include <stdio.h>

void perror_with_exit(int exit_code, char *err_msg)
{
    perror(err_msg);
    exit(exit_code);       
}