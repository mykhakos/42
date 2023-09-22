/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:43:35 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:10:19 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "../utils/utils.h"
# include "../stack/stack.h"
# include "../push_swap_ops/push_swap_ops.h"
# include "../../libft/libft.h"

typedef struct s_op
{
	char		*name;
	struct s_op	*next;
}				t_op;

t_op			*create_op(char *op_name);
t_op			*read_ops(int fd);
void			deallocate_ops(t_op **ops);
int				run_ops(t_op *ops, t_stack **stack_a, t_stack **stack_b);
#endif
