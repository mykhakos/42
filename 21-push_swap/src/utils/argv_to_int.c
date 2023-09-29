/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:03:29 by kmykhail          #+#    #+#             */
/*   Updated: 2023/09/21 18:08:57 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	*argv_to_int(int argc, char **argv)
{
	int	i;
	int	*argv_int;

	argv_int = malloc((argc - 1) * sizeof(int));
	if (argv_int == NULL)
		exit(1);
	i = 0;
	while (i < argc - 1)
	{
		if (!is_number(argv[i + 1]) || !is_int(argv[i + 1]))
		{
			free(argv_int);
			exit_with_error_msg(0, "Error");
		}
		argv_int[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (argv_int);
}
