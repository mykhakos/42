/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:59:25 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 17:59:28 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

static int	get_min(int val1, int val2)
{
	if (val1 <= val2)
		return (val1);
	return (val2);
}

t_rot_ops	*create_rot_ops(int ra, int rb, int rra, int rrb)
{
	t_rot_ops	*ops;

	ops = malloc(sizeof(t_rot_ops));
	if (ops == NULL)
		exit(1);
	ops->rr = get_min(ra, rb);
	ops->ra = ra - ops->rr;
	ops->rb = rb - ops->rr;
	ops->rrr = get_min(rra, rrb);
	ops->rra = rra - ops->rrr;
	ops->rrb = rrb - ops->rrr;
	ops->total = ops->ra + ops->rb + ops->rr + ops->rra + ops->rrb + ops->rrr;
	return (ops);
}
