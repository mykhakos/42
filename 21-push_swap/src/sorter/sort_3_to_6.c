#include "sorter.h"


void rot_a_until_min_a_is_first(t_stack **stack_a, t_stack **stack_b)
{
    t_rot_ops *next_rot_ops;
    next_rot_ops = find_opt_rots_min_a_is_first(*stack_a);
    run_rot_ops(stack_a, stack_b, &next_rot_ops);
}

void push_to_b_until_a_has_3(t_stack **stack_a, t_stack **stack_b)
{
    while (find_len(*stack_a) > 3)
    {
        rot_a_until_min_a_is_first(stack_a, stack_b);
        run_push_op(stack_a, stack_b, 1, "pb");
    }
}

void push_to_a_until_b_is_empty(t_stack **stack_a, t_stack **stack_b)
{
    t_rot_ops *next_rot_ops;

    while (find_len(&stack_b) != 0)
    {
        run_push_op(stack_b, stack_a, 1, "pa");
    }
}

void sort_3(t_stack **stack)
{
    int top;
    int middle;
    int bottom;

    top = (*stack)->value;
    middle = (*stack)->next->value;
    bottom = (*stack)->next->next->value;
    if ((top < bottom && bottom < middle) ||
        (bottom < middle && middle < top) ||
        (middle < bottom && bottom < top))
    {
        run_swap_op(stack, 1, "sa");
    }
}

void sort_4_to_6(t_stack **stack_a, t_stack **stack_b)
{
    push_to_b_until_a_has_3(stack_a, stack_b);
    sort_3(stack_a);
    rot_a_until_min_a_is_first(stack_a, stack_b);
    push_to_a_until_b_is_empty(stack_a, stack_b);
}