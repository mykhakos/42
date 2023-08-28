#include "stack.h"


void reverse_stack(t_stack **root)
{
    t_stack *prev;
    t_stack *curr;
    t_stack *next;

    prev = NULL;
    curr = *root;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev;
}
