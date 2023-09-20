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

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int *argv_int;

    if (argc == 1)
        exit_with_error_msg(0, "Enter a list of integers to sort.");
    argv_int = argv_to_int(argc, argv);
    if (has_dup(argv_int, argc - 1))
    {
        free(argv_int);
        exit_with_error_msg(0, "Error");
    }
    stack_a = create_stack(argv_int, argc - 1);
    stack_b = NULL;
    free(argv_int);
    sort(&stack_a, &stack_b);
    deallocate_stack(&stack_a);
    return (0);
}