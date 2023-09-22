/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:02:40 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:09:00 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len += 1;
		stack = stack->next;
	}
	return (len);
}

t_stack	*find_last(t_stack *stack)
{
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}
