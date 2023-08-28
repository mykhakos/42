#ifndef PUSH_SWAP_OPS_OPS_H
    #define PUSH_SWAP_OPS_OPS_H

    #include "../stack/stack.h"

    void push(t_stack **stack_from, t_stack **t_stacko);
    void rotate(t_stack **stack);
    void reverse_rotate(t_stack **stack);
    void swap(t_stack **stack);
    void run_rot_op(t_stack **stack, 
                    void (*rot_op) (t_stack **), 
                    int repeat, 
                    char *op_name);
    void run_rot_ops(
        t_stack **stack_a, t_stack **stack_b, t_rot_ops **ops_ptr);
    void run_push_op(
        t_stack **stack_from, t_stack **stack_to, int repeat, char *op_name);
    void run_swap_op(
        t_stack **stack, int repeat, char *op_name);

#endif
