#include "stack.h"


int is_first(t_stack *stack, int value)
{
    return (stack->value == value);
}

int is_ready_for_push(t_stack *stack, int value)
{
    t_stack *last;

    last = stack;
    while (last->next != NULL)
    {
        last = last->next;
    }
    return (stack->value > value && last->value < value);
}
