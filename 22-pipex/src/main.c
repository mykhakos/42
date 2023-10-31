/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:53:25 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/31 20:43:50 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

#define ARG_COUNT 4

static void	check_arg_count(int arg_count)
{
	if (arg_count != ARG_COUNT)
	{
		dup2(STDOUT_FILENO, STDERR_FILENO);
		ft_printf("Invalid arg count (expected %i, got %i).\n", ARG_COUNT,
			arg_count);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_command	*commands;
	int			pipefd[2];
	int			curr_pid;

	check_arg_count(argc - 1);
	if (pipe(pipefd) == -1)
		perror_with_exit("pipe", EXIT_FAILURE);
	commands = argv_to_commands_list(argc, argv, env);
	curr_pid = exec_cmd_first(commands->command_args, pipefd, argv[1], env);
	if (curr_pid != 0)
		curr_pid = exec_cmd_last(commands->next->command_args, pipefd, argv[4],
				env);
	if (curr_pid != 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		wait(NULL);
		wait(NULL);
	}
	deallocate_commands(&commands);
	return (0);
}
