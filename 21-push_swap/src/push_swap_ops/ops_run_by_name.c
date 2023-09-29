/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_run_by_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:53:40 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:17:40 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_ops.h"

static int	run_swap(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(op, "sa", 2) == 0)
	{
		swap(stack_a);
		return (0);
	}
	else if (ft_strncmp(op, "sb", 2) == 0)
	{
		swap(stack_b);
		return (0);
	}
	else if (ft_strncmp(op, "ss", 2) == 0)
	{
		swap(stack_a);
		swap(stack_b);
		return (0);
	}
	else
	{
		return (1);
	}
}

static int	run_push(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(op, "pa", 2) == 0)
	{
		push(stack_b, stack_a);
		return (0);
	}
	else if (ft_strncmp(op, "pb", 2) == 0)
	{
		push(stack_a, stack_b);
		return (0);
	}
	else
	{
		return (1);
	}
}

static int	run_reverse_rotate(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(op, "rra", 3) == 0)
	{
		reverse_rotate(stack_a);
		return (0);
	}
	else if (ft_strncmp(op, "rrb", 3) == 0)
	{
		reverse_rotate(stack_b);
		return (0);
	}
	else if (ft_strncmp(op, "rrr", 3) == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		return (0);
	}
	else
	{
		return (1);
	}
}

static int	run_rotate(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(op, "ra", 2) == 0)
	{
		rotate(stack_a);
		return (0);
	}
	else if (ft_strncmp(op, "rb", 2) == 0)
	{
		rotate(stack_b);
		return (0);
	}
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		return (0);
	}
	else
	{
		return (1);
	}
}

int	run_op_by_name(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(op, "s", 1) == 0 && ft_strlen(op) == 3)
		return (run_swap(op, stack_a, stack_b));
	else if (ft_strncmp(op, "p", 1) == 0 && ft_strlen(op) == 3)
		return (run_push(op, stack_a, stack_b));
	else if (ft_strncmp(op, "r", 1) == 0 && ft_strlen(op) == 3)
		return (run_rotate(op, stack_a, stack_b));
	else if (ft_strncmp(op, "rr", 2) == 0 && ft_strlen(op) == 4)
		return (run_reverse_rotate(op, stack_a, stack_b));
	else
		return (1);
}
