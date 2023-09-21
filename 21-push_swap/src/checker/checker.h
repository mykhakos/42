#ifndef CHECKER_CHECKER_H
    #define CHECKER_CHECKER_H

    #include <stdlib.h>
    #include "../utils/utils.h"
    #include "../stack/stack.h"
    #include "../push_swap_ops/push_swap_ops.h"
    #include "../../libft/libft.h"

    typedef struct s_op
    {
        char *name;
        struct s_op *next;
    } t_op;

    t_op *create_op(char *op_name);
    t_op *read_ops(int fd);
    void deallocate_ops(t_op **ops);
    int run_ops(t_op *ops, t_stack **stack_a, t_stack **stack_b);
#endif