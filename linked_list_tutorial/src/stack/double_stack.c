#include "stack.h"

t_double_stack *create_double_stack(t_stack **stack_a, t_stack **stack_b)
{
    t_double_stack *dstack;

    dstack = malloc(sizeof(t_double_stack));
    if (dstack == NULL)
        return (NULL);
    dstack->a = stack_a;
    dstack->b = stack_b;
    return (dstack);
}