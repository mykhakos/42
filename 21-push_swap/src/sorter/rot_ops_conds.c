#include "sorter.h"


int is_first(t_stack *stack, int value)
{
    return (stack->value == value);
}

int is_ready_for_push(t_stack *stack, int value)
{
    t_stack *last_node;

    last_node = find_last(stack);
  

    //print_stack(stack, "a");
    //ft_printf(
    //    "first: %i\nlast:  %i\nvalue: %i\n-----\nis_ready_for_push returning %i\n\n",
    //    stack->value, last_node->value, value, stack->value > value && last_node->value < value);
    return (stack->value > value && last_node->value < value);
}
