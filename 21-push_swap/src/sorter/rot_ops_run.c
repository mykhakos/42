#include "sorter.h"


void run_rot_ops(t_stack **stack_a, t_stack **stack_b, t_rot_ops **ops_ptr)
{
    t_double_stack *dstack;
    t_rot_ops *ops = *ops_ptr;

    dstack = create_double_stack(stack_a, stack_b);
    if (dstack == NULL && (ops->rr || ops->rrr))
        exit(1);
    run_rot_op(stack_a, rotate, ops->ra, "ra");
    run_rot_op(stack_a, reverse_rotate, ops->rra, "rra");
    run_rot_op(stack_b, rotate, ops->rb, "rb");
    run_rot_op(stack_b, reverse_rotate, ops->rrb, "rrb");
    run_rot_op_double(dstack, rotate, ops->rr, "rr");
    run_rot_op_double(dstack, rotate, ops->rrr, "rrr");
    free(dstack);
    free(ops);
    *ops_ptr = NULL;
}
