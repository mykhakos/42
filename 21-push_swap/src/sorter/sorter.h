/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:00:50 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:21:37 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "../stack/stack.h"
# include "../push_swap_ops/push_swap_ops.h"

typedef struct s_rot_ops
{
	int		total;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_rot_ops;

int			is_first(t_stack *stack, int value);
int			is_ready_for_push(t_stack *stack, int value);
int			rots_direct(t_stack *stack, int value, int (*cond)(t_stack *, int));
int			rots_reverse(t_stack *stack, int value, int (*cond)(t_stack *,
					int));
t_rot_ops	*find_opt_rots_push_to_a(t_stack *stack_a, t_stack *stack_b);
t_rot_ops	*find_opt_rots_min_a_is_first(t_stack *stack_a);
t_rot_ops	*create_rot_ops(int ra, int rb, int rra, int rrb);
void		run_rot_ops(t_stack **stack_a, t_stack **stack_b,
				t_rot_ops **ops_ptr);
void		rot_a_until_min_a_is_first(t_stack **stack_a, t_stack **stack_b);
void		sort_3(t_stack **stack);
void		sort_4_to_6(t_stack **stack_a, t_stack **stack_b);
void		sort_7_plus(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);

#endif