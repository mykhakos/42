# include "sorter.h"


int rots_direct(t_stack *stack, int value, int (*cond) (t_stack *, int))
{
    int rots;
    int first_val;

    if (stack == NULL)
        return (-1);
    rots = 0;
    first_val = stack->value;
    //ft_printf("%s: ", "before");
    //print_stack(stack, "a");
    while (1)
    {
        if (cond(stack, value))
        {
            //ft_printf("%s:  ", "after");
            //print_stack(stack, "a");
            //ft_printf("\t%s\n", "(cond satisfied)");
            return (rots);
        }
        //ft_printf("%s:  ", "after");
        //print_stack(stack, "a");
        //ft_printf("\t%s\n", "(cond not satisfied, before rot)");         
        rotate(&stack);
        //ft_printf("%s:  ", "after");
        //print_stack(stack, "a");
        //ft_printf("\t%s\n", "(cond not satisfied, after rot)"); 
        if (stack->value == first_val)
            return (-1);
        rots += 1;
    }
}

int rots_reverse(t_stack *stack, int value, int (*cond) (t_stack *, int))
{
    int rots;
    int stack_len;

    rots = rots_direct(stack, value, cond);
    stack_len = find_len(stack);
    if (rots == -1 || stack_len == -1)
        return (-1);
    return (stack_len - rots);
}
