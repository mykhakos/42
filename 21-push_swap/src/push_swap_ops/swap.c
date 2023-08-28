#include "ops.h"

void swap(t_stack **stack)
{
    t_stack *temp;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    temp = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    temp->next = *stack;
    *stack = temp;
}
