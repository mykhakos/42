/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:53:25 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/24 20:40:11 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

#define ARG_COUNT 4

static void check_arg_count(int arg_count)
{
	if (arg_count != ARG_COUNT)
	{
		dup2(STDOUT_FILENO, STDERR_FILENO);
		ft_printf("Invalid arg count (expected %i, got %i).\n", ARG_COUNT, arg_count);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_command	*commands;
	int			pipefd[2];

	check_arg_count(argc - 1);
	commands = argv_to_commands_list(argc, argv, env);
	if (pipe(pipefd) == -1)
		perror_with_exit("pipe", EXIT_FAILURE);
	exec_cmd_first(commands->command_args, pipefd, argv[1], env);
	
	exec_cmd_last(commands->next->command_args, pipefd, argv[4], env);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	deallocate_commands(&commands);
	return (0);
}
