# include "sorter.h"


int rots_direct(t_stack *stack, int value, int (*cond) (t_stack *, int))
{
    int rots;

    if (stack == NULL)
        return (-1);
    rots = 0;
    while (stack != NULL)
    {
        if (cond(stack, value))
            return (rots);
        stack = stack->next;
        rots += 1;
    }
    return (-1);
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
