#include "stack.h"


void remove_node(t_stack **root, int value)
{
    t_stack *to_remove;
    t_stack *curr;

    if (*root == NULL)
        return ;
    if ((*root)->value == value)
    {
        to_remove = *root;
        *root = (*root)->next;
        free(to_remove);
        return ;
    }
    curr = *root;
    while (curr->next != NULL)
    {
        if (curr->next->value == value)
        {
            to_remove = curr->next;
            curr->next = curr->next->next;
            free(to_remove);
            return ;
        }
        curr = curr->next;
    }
}