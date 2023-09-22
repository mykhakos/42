/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:02:57 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:25:17 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*put_min_first(t_stack *stack)
{
	t_stack	*stack_copy;
	t_stack	*first;
	t_stack	*before_min;
	t_stack	*min;

	stack_copy = copy_stack(stack);
	first = stack_copy;
	before_min = NULL;
	min = stack_copy;
	while (stack_copy->next != NULL)
	{
		if (stack_copy->next->value < min->value)
		{
			before_min = stack_copy;
			min = stack_copy->next;
		}
		stack_copy = stack_copy->next;
	}
	if (before_min)
	{
		stack_copy->next = first;
		before_min->next = NULL;
	}
	return (min);
}

int	is_in_order(t_stack *stack)
{
	t_stack	*stack_copy;
	int		in_order;

	stack_copy = put_min_first(stack);
	in_order = is_sorted(stack_copy);
	deallocate_stack(&stack_copy);
	return (in_order);
}
