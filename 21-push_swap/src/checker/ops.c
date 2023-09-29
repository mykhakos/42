/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:13:36 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:13:37 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_op	*create_op(char *op_name)
{
	t_op	*node;

	node = malloc(sizeof(t_op));
	if (node == NULL)
		exit(1);
	node->next = NULL;
	node->name = op_name;
	return (node);
}

void	deallocate_ops(t_op **ops)
{
	t_op	*curr_node;
	t_op	*next_node;

	curr_node = *ops;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		free(curr_node->name);
		free(curr_node);
		curr_node = next_node;
	}
}

t_op	*read_ops(int fd)
{
	t_op	*ops;
	t_op	*ops_head;
	char	*op_name;

	ops = NULL;
	ops_head = NULL;
	while (1)
	{
		op_name = get_next_line(fd);
		if (op_name == NULL)
			break ;
		if (ops != NULL)
		{
			ops->next = create_op(op_name);
			ops = ops->next;
		}
		else
		{
			ops = create_op(op_name);
			ops_head = ops;
		}
	}
	return (ops_head);
}

int	run_ops(t_op *ops, t_stack **stack_a, t_stack **stack_b)
{
	while (ops != NULL)
	{
		if (run_op_by_name(ops->name, stack_a, stack_b) == 1)
			return (1);
		ops = ops->next;
	}
	return (0);
}
