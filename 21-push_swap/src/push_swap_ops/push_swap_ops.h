#ifndef PUSH_SWAP_OPS_PUSH_SWAP_OPS_H
    #define PUSH_SWAP_OPS_PUSH_SWAP_OPS_H

    #include "../stack/stack.h"
    #include "../../libft/libft.h"

    int push(t_stack **stack_from, t_stack **stack_to);
    int rotate(t_stack **stack);
    int reverse_rotate(t_stack **stack);
    int swap(t_stack **stack);
    void run_rot_op(t_stack **stack, 
                    int (*rot_op) (t_stack **), 
                    int repeat, 
                    char *op_name);
    void run_rot_op_double(t_double_stack *dstack,
                           int (*rot_op) (t_stack **), 
                           int repeat, 
                           char *op_name);
    void run_push_op(
        t_stack **stack_from, t_stack **stack_to, int repeat, char *op_name);
    void run_swap_op(
        t_stack **stack, int repeat, char *op_name);
    int run_op_by_name(char *op, t_stack **stack_a, t_stack **stack_b);

#endif
