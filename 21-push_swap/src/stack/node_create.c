#include "stack.h"

t_stack *create_node(int value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (node == NULL)
        exit(1);
    node->next = NULL;
    node->value = value;
    return (node);
}
