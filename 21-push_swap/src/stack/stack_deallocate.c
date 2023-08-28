#include "stack.h"


void deallocate_stack(t_stack **root)
{
    t_stack *curr;
    t_stack *next;

    curr = *root;
    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
}
