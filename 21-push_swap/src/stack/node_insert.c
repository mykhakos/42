#include "stack.h"


void insert_node_beginning(t_stack **root, int value)
{
    t_stack *new;

    new = create_node(value);
    new->next = *root;
    *root = new;
}

void insert_node_after(t_stack *node, int value)
{
    t_stack *new;

    new = create_node(value);
    new->next = node->next;
    node->next = new;
}

void insert_node_end(t_stack **root, int value)
{
    t_stack *new;
    t_stack *curr;

    new = create_node(value);
    if (*root == NULL)
    {
        *root = new;
        return ;
    }
    curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new;
}
