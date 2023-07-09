#include <stdio.h>
#include "libft/libft.h"

int main(int argc, char **argv) {
    // If no arguments were provided
    if (argc == 1) {
        ft_putendl_fd("Provide a list of integer values separated by a whitespace", 1);
        return 0;
    }

    // Iterate through the arguments
    for (int i = 1; i < argc; i++) {
        // If the argument is not a number
        if (!ft_isdigit(*argv[i])) {
            ft_putendl_fd("Error", 1);
            return 0;
        }
    }

    // Here, you can continue with the push_swap program
    // For now, it just prints "OK"
    ft_putendl_fd("OK", 1);

    return 0;
}