#include "ops.h"


void rotate(t_stack **stack)
{
    t_stack *curr;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    curr = *stack;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = *stack;
    *stack = (*stack)->next;
    curr->next->next = NULL;
}

void reverse_rotate(t_stack **stack)
{
    t_stack *curr;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    curr = *stack;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    curr->next->next = *stack;
    *stack = curr;
    curr->next = NULL;
}