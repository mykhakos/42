#include "sorter.h"


void push_to_b_until_a_has_3_with_presort(t_stack **stack_a, t_stack **stack_b)
{
    int min_a;
    int med_a;
    int max_a;

    min_a = find_min(&stack_a);
    max_a = find_max(&stack_a);
    med_a = ((min_a + max_a) / 2);
    while (find_len(*stack_a) > 3)
    {
        if ((*stack_a)->value == min_a || (*stack_a)->value == max_a)
        {
            run_rot_op(stack_a, rotate, 1, "ra");
        }
        else 
        {
            run_push_op(stack_a, stack_a, 1, "pb");
            if ((*stack_a)->value > med_a)
                run_rot_op(stack_b, rotate, 1, "rb");
        }
    }
}

void push_to_a_until_b_is_empty(t_stack **stack_a, t_stack **stack_b)
{
    t_rot_ops *next_rot_ops;

    while (find_len(*stack_b) != 0)
    {
        next_rot_ops = find_opt_rots_push_to_a(stack_a, stack_b);
        run_rot_ops(stack_a, stack_b, &next_rot_ops);
        run_push_op(stack_b, stack_a, 1, "pa");
    }
}

void sort_7_plus(t_stack **stack_a, t_stack **stack_b)
{
    push_to_b_until_a_has_3_with_presort(stack_a, stack_b);
    sort_3(stack_a);
    push_to_a_until_b_is_empty(stack_a, stack_b);
}