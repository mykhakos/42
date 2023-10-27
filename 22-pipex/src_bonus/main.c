/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:14 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 22:20:52 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

#define MIN_ARG_COUNT 3
#define MIN_ARG_COUNT_HERE_DOC 4
#define HERE_DOC_TEMPFILE "tempfile"
#define HERE_DOC_KW "here_doc"

static void	check_arg_count(int expected_arg_count, int actual_arg_count)
{
	if (actual_arg_count < expected_arg_count)
	{
		dup2(STDOUT_FILENO, STDERR_FILENO);
		ft_printf("Too few args (expected at least %i, got %i).\n",
			expected_arg_count, actual_arg_count);
		exit(EXIT_FAILURE);
	}
}

void	handle_here_doc(t_command **commands, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], HERE_DOC_KW, ft_strlen(HERE_DOC_KW)))
	{
		check_arg_count(MIN_ARG_COUNT_HERE_DOC, argc - 1);
		read_and_save_user_input(HERE_DOC_TEMPFILE, argv[2]);
		remove_here_doc_from_commands(commands);
		argv[1] = HERE_DOC_TEMPFILE;
	}
}

void	exec_cmd_multi(t_command *commands, char *infile, char *outfile,
		char **env)
{
	int	command_count;
	int	i;
	int	(*pipefd)[2];

	command_count = count_commands(commands);
	open_pipes(&pipefd, command_count - 1);
	exec_cmd_first(commands->command_args, pipefd[0], infile, env);
	close(pipefd[0][1]);
	commands = commands->next;
	i = 1;
	while (commands->next != NULL)
	{
		exec_cmd_middle(commands->command_args, pipefd[i - 1], pipefd[i], env);
		close(pipefd[i - 1][0]);
		close(pipefd[i][1]);
		commands = commands->next;
		i++;
	}
	exec_cmd_last(commands->command_args, pipefd[i - 1], outfile, env);
	free(pipefd);
}

int	main(int argc, char **argv, char **env)
{
	t_command	*commands;
	int			command_count;
	int			i;

	check_arg_count(MIN_ARG_COUNT, argc - 1);
	commands = argv_to_commands_list(argc, argv, env);
	handle_here_doc(&commands, argc, argv);
	command_count = count_commands(commands);
	if (command_count == 1)
		exec_cmd_single(commands->command_args, argv[1], argv[argc - 1], env);
	else
		exec_cmd_multi(commands, argv[1], argv[argc - 1], env);
	i = 0;
	while (i < command_count)
	{
		wait(NULL);
		i++;
	}
	deallocate_commands(&commands);
	if (!ft_strncmp(argv[1], HERE_DOC_TEMPFILE, ft_strlen(HERE_DOC_TEMPFILE)))
		remove_file(HERE_DOC_TEMPFILE);
	return (0);
}
