/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops_conds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:58:57 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:09:06 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	is_first(t_stack *stack, int value)
{
	return (stack->value == value);
}

int	is_ready_for_push(t_stack *stack, int value)
{
	t_stack	*last_node;

	last_node = find_last(stack);
	return (stack->value > value && last_node->value < value);
}
