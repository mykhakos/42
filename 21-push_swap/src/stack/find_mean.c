#include "stack.h"


int find_mean(t_stack *stack)
{
    int sum;
    int len;

    sum = 0;
    len = 0;
    while (stack != NULL)
    {
        sum += stack->value;
        len += 1;
        stack = stack->next;
    }
    return (sum / len);
}