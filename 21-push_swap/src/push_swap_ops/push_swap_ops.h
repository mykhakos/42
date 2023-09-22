/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:57:22 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:18:28 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPS_H
# define PUSH_SWAP_OPS_H

# include "../../libft/libft.h"
# include "../stack/stack.h"

int		push(t_stack **stack_from, t_stack **stack_to);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);
int		swap(t_stack **stack);
void	run_rot_op(t_stack **stack, int (*rot_op)(t_stack **), int repeat,
			char *op_name);
void	run_rot_op_double(t_double_stack *dstack, int (*rot_op)(t_stack **),
			int repeat, char *op_name);
void	run_push_op(t_stack **stack_from, t_stack **stack_to, int repeat,
			char *op_name);
void	run_swap_op(t_stack **stack, int repeat, char *op_name);
int		run_op_by_name(char *op, t_stack **stack_a, t_stack **stack_b);

#endif
