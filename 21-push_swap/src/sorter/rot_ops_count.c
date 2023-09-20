# include "sorter.h"


int rots_direct(t_stack *stack, int value, int (*cond) (t_stack *, int))
{
    int rots;
    int first_val;
    t_stack *stack_cpy;

    if (stack == NULL)
        return (-1);
    rots = 0;
    first_val = stack->value;
    stack_cpy = copy_stack(stack);
    while (1)
    {
        if (cond(stack_cpy, value))
        {
            deallocate_stack(&stack_cpy);
            return (rots);
        }       
        rotate(&stack_cpy);
        if (stack_cpy->value == first_val)
        {
            deallocate_stack(&stack_cpy);
            return (-1);
        }
        rots += 1;
    }
}

int rots_reverse(t_stack *stack, int value, int (*cond) (t_stack *, int))
{
    int rots;
    int stack_len;

    rots = rots_direct(stack, value, cond);
    stack_len = find_len(stack);
    if (rots == -1 || stack_len == -1)
        return (-1);
    return (stack_len - rots);
}
