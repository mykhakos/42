#include "stack.h"
#include "../../libft/libft.h"

void print_stack(t_stack *stack, char *name)
{
    ft_printf("stack %s: ", name);
    while (stack)
    {
        ft_printf("%i ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}