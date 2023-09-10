#include "push_swap_ops.h"


#include <string.h>
int PRINT = 0;


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
        if (res && PRINT)
        {
            ft_printf("%s\n", "----------");
            if (strstr(op_name, "a"))
            {
                ft_printf("%s: ", "A");
                print_stack(*stack, "");
                ft_printf("%s: \n", "B");  
            }
            else
            {
                ft_printf("%s: \n", "A");
                ft_printf("%s: ", "B");  
                print_stack(*stack, "");
            }                          
            
            ft_printf("%s", "\n");
        }
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
        if ((res1 || res2) && PRINT)
        {
            ft_printf("%s\n", "----------");
            ft_printf("%s: ", "A");                   
            print_stack(*(dstack->a), "a");
            ft_printf("%s: ", "B");   
            print_stack(*(dstack->b), "b");
            ft_printf("%s", "\n");
        }   
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
        if (res && PRINT)
        {
            ft_printf("%s\n", "----------");
            if (strstr(op_name, "a"))
            {
                ft_printf("%s: ", "A");     
                print_stack(*stack_to, "");   
                ft_printf("%s: ", "B");            
                print_stack(*stack_from, "");
            }
            else
            {
                ft_printf("%s: ", "A");     
                print_stack(*stack_from, "");   
                ft_printf("%s: ", "B");            
                print_stack(*stack_to, "");                
            }
            ft_printf("%s", "\n");
        }        
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
        if (res && PRINT)
        {
            ft_printf("%s\n", "----------");
            if (strstr(op_name, "a"))
            {
                ft_printf("%s: ", "A");
                print_stack(*stack, "");
                ft_printf("%s: \n", "B");  
            }
            else
            {
                ft_printf("%s: \n", "A");
                ft_printf("%s: ", "B");  
                print_stack(*stack, "");
            }                            
            
            ft_printf("%s", "\n");
        } 
    }
}
