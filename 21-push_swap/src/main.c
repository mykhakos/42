#include "main.h"


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int *argv_int;
    int i;

    while (argc == 1)
        exit_with_error_msg(
            0, "Enter a list of integers to sort (example: 2 1 3 6 5 8).");
    argv_int = malloc((argc - 1) * sizeof(int));
    if (argv_int == NULL)
        return(1);
    i = 0;
    while (i < argc - 1)
    {
        if (!is_number(argv[i + 1]) || !is_int(argv[i + 1]))
            exit_with_error_msg(0, "Error");
        argv_int[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    if (has_dup(argv_int, argc - 1))
            exit_with_error_msg(0, "Error");
    stack_a = create_stack(argv_int, argc - 1);
    stack_b = NULL;
    free(argv_int);
    //print_stack(stack_a, "a");
    sort(&stack_a, &stack_b);
    if (is_sorted(stack_a) == 0)
        print_stack(stack_a, "a");
    else
        ft_printf("%s\n", "sorted.\n");
    deallocate_stack(&stack_a);
}