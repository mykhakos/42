#include "ops.h"

void push(t_stack **stack_from, t_stack **t_stacko)
{
    t_stack *node;

    if (*stack_from == NULL)
        return ;
    node = *stack_from;
    *stack_from = (*stack_from)->next;
    node->next = *t_stacko;
    *t_stacko = node;
}
