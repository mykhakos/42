#include "stack.h"


int find_len(t_stack *stack)
{
    int len;

    len = 0;
    while (stack != NULL)
    {
        len += 1;
        stack = stack->next;
    }
    return (len);
}

t_stack *find_last(t_stack *stack)
{
    while (stack->next != NULL)
    {
        stack = stack->next;
    }
    return (stack);
}