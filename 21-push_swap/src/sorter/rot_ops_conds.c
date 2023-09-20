#include "sorter.h"


int is_first(t_stack *stack, int value)
{
    return (stack->value == value);
}

int is_ready_for_push(t_stack *stack, int value)
{
    t_stack *last_node;

    last_node = find_last(stack);
    return (stack->value > value && last_node->value < value);
}
