#include "stack.h"


int find_value_index(t_stack *stack, int value)
{
    int value_index;

    if (stack == NULL)
        return (-1);
    value_index = 0;
    while (stack != NULL)
    {
        if (stack->value == value)
            return (value_index);
        stack = stack->next;
        value_index += 1;
    }
    return (-1);
}