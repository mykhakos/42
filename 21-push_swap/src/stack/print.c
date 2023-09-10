#include "stack.h"
#include "../../libft/libft.h"

void print_stack(t_stack *stack, char *name)
{
    if (name && 0)
        return ;
    while (stack)
    {
        ft_printf("%i ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}