#include "ops.h"
#include "../smart_rotate/smart_rotate.h"

void run_rot_op(t_stack **stack, 
                void (*rot_op) (t_stack **), 
                int repeat, 
                char *op_name)
{
    while (repeat--)
    {
        rot_op(stack);
        ft_printf("%s\n", op_name);
    }
}

void run_rot_op_double(t_double_stack *dstack,
                       void (*rot_op) (t_stack **), 
                       int repeat, 
                       char *op_name)
{
    while (repeat--)
    {
        rot_op(dstack->a);
        rot_op(dstack->b);
        ft_printf("%s\n", op_name);
    }
}

void run_push_op(t_stack **stack_from,
                 t_stack **stack_to, 
                 int repeat, 
                 char *op_name)
{
    while (repeat--)
    {
        push(stack_from, stack_to);
        ft_printf("%s\n", op_name);
    }    
}

void run_swap_op(t_stack **stack, int repeat, char *op_name)
{
    while (repeat--)
    {
        swap(stack);
        ft_printf("%s\n", op_name);
    }    
}