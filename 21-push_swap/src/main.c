/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:03:49 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:35:10 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*argv_int;

	if (argc == 1)
		exit_with_error_msg(0, "Enter a list of integers to sort.");
	argv_int = argv_to_int(argc, argv);
	if (has_dup(argv_int, argc - 1))
	{
		free(argv_int);
		exit_with_error_msg(0, "Error");
	}
	stack_a = create_stack(argv_int, argc - 1);
	stack_b = NULL;
	free(argv_int);
	sort(&stack_a, &stack_b);
	deallocate_stack(&stack_a);
	deallocate_stack(&stack_b);
	return (0);
}
