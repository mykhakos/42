#include "checker.h"


void run_ops_with_dealloc(t_op **ops, t_stack **stack_a, t_stack **stack_b)
{
    if (run_ops(*ops, stack_a, stack_b) == 1)
    {
        deallocate_ops(ops);
        deallocate_stack(stack_a);
        deallocate_stack(stack_b);
        exit_with_error_msg(0, "Error");
    }
    else
    {
        if (is_sorted(*stack_a))
            ft_printf("%s\n", "OK");
        else
            ft_printf("%s\n", "KO");
        deallocate_ops(ops);
        deallocate_stack(stack_a);
        deallocate_stack(stack_b);
    }
}

int main(int argc, char **argv)
{
    int *argv_int;
    t_op *ops;
    t_stack *stack_a;
    t_stack *stack_b;

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
    ops = read_ops(STDIN_FILENO);
    run_ops_with_dealloc(&ops, &stack_a, &stack_b);
    return (0);
}
