#include "push_swap_ops.h"


void run_rot_op(t_stack **stack, 
                int (*rot_op) (t_stack **), 
                int repeat, 
                char *op_name)
{
    int res;

    while (repeat--)
    {
        res = rot_op(stack);
        if (res)
            ft_printf("%s\n", op_name);
    }
}

void run_rot_op_double(t_double_stack *dstack,
                       int (*rot_op) (t_stack **), 
                       int repeat, 
                       char *op_name)
{
    int res1;
    int res2;

    while (repeat--)
    {
        res1 = rot_op(dstack->a);
        res2 = rot_op(dstack->b);
        if (res1 || res2)
            ft_printf("%s\n", op_name);
    }
}

void run_push_op(t_stack **stack_from,
                 t_stack **stack_to, 
                 int repeat, 
                 char *op_name)
{
    int res;

    while (repeat--)
    {
        res = push(stack_from, stack_to);
        if (res)
            ft_printf("%s\n", op_name);
    }    
}

void run_swap_op(t_stack **stack, int repeat, char *op_name)
{
    int res;

    while (repeat--)
    {
        res = swap(stack);
        if (res)
            ft_printf("%s\n", op_name);
    }
}
