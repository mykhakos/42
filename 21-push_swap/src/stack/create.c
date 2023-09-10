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

t_stack *create_stack(int *values, int values_count)
{
    t_stack *stack;
    t_stack *next_node;

    stack = create_node(*values);
    next_node = stack;
    values++;
    values_count--;
    while (values_count)
    {
        next_node->next = create_node(*values);
        next_node = next_node->next;
        values++;
        values_count--;
    }
    return (stack);
}

t_stack *copy_stack(t_stack *stack)
{
    t_stack *stack_copy;
    t_stack *next_node;

    if (stack == NULL)
        return (NULL);
    stack_copy = create_node(stack->value);
    next_node = stack_copy;
    stack = stack->next;
    while (stack != NULL)
    {
        next_node->next = create_node(stack->value);
        next_node = next_node->next;
        stack = stack->next;
    }
    return (stack_copy);
}


t_double_stack *create_double_stack(t_stack **stack_a, t_stack **stack_b)
{
    t_double_stack *dstack;

    dstack = malloc(sizeof(t_double_stack));
    if (dstack == NULL)
        return (NULL);
    dstack->a = stack_a;
    dstack->b = stack_b;
    return (dstack);
}

void deallocate_stack(t_stack **stack)
{
    t_stack *curr_node;
    t_stack *next_node;

    curr_node = *stack;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
}
