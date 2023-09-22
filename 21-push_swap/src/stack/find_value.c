/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:02:45 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:08:59 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_value(t_stack *stack, int (*checker)(int, int))
{
	int	value;

	value = stack->value;
	stack = stack->next;
	while (stack != NULL)
	{
		if (checker(stack->value, value))
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}

int	checker_is_less(int value, int curr_min)
{
	return (value < curr_min);
}

int	checker_is_more(int value, int curr_max)
{
	return (value > curr_max);
}

int	find_min(t_stack *stack)
{
	return (find_value(stack, checker_is_less));
}

int	find_max(t_stack *stack)
{
	return (find_value(stack, checker_is_more));
}
