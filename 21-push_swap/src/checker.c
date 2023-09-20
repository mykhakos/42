#include "main.h"


int *argv_to_int(int argc, char **argv)
{
    int i;
    int *argv_int;

    argv_int = malloc((argc - 1) * sizeof(int));
    if (argv_int == NULL)
        exit(1);
    i = 0;
    while (i < argc - 1)
    {
        if (!is_number(argv[i + 1]) || !is_int(argv[i + 1]))
        {
            free(argv_int);
            exit_with_error_msg(0, "Error");
        }
        argv_int[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    return (argv_int);
}

#define BUFFER_SIZE 1024

ssize_t read_input(char *buffer, size_t size) {
    ssize_t bytesRead = read(0, buffer, size - 1);
    if (bytesRead < 0) {
        //perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';  // Null-terminate the buffer
    return bytesRead;
}

int main() {
    char buffer[BUFFER_SIZE];

    // Read from standard input
    ssize_t bytesRead = read_input(buffer, sizeof(buffer));
    if (bytesRead > 0) {
        ft_printf("Read: %s\n", buffer);
    } else {
        ft_printf("No input or EOF reached\n");
    }

    return 0;
}
