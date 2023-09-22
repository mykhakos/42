/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:57:08 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:09:07 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_ops.h"

int	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*node;

	if (*stack_from == NULL)
		return (0);
	node = *stack_from;
	*stack_from = (*stack_from)->next;
	node->next = *stack_to;
	*stack_to = node;
	return (1);
}

int	swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
	return (1);
}

int	rotate(t_stack **stack)
{
	t_stack	*curr;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = *stack;
	*stack = (*stack)->next;
	curr->next->next = NULL;
	return (1);
}

int	reverse_rotate(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	curr = *stack;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	last = curr->next;
	last->next = *stack;
	*stack = last;
	curr->next = NULL;
	return (1);
}
