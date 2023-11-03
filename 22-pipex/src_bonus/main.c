/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:14 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/03 18:21:52 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

#define MIN_ARG_COUNT 3
#define MIN_ARG_COUNT_HERE_DOC 4
#define HERE_DOC_TEMPFILE "tempfile"
#define HERE_DOC_KW "here_doc"

static void	handle_here_doc(t_command **commands, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], HERE_DOC_KW, ft_strlen(HERE_DOC_KW)))
	{
		check_arg_count(MIN_ARG_COUNT_HERE_DOC, argc - 1);
		read_and_save_user_input(HERE_DOC_TEMPFILE, argv[2]);
		remove_here_doc_from_commands(commands);
		argv[1] = HERE_DOC_TEMPFILE;
	}
}

static int	exec_cmd_middle_from_parent(t_command *commands, int (*pipefd)[2],
		char **env)
{
	int	curr_pid;
	int	i;

	i = 1;
	while (commands->next != NULL)
	{
		//ft_printf("exec: %s (i=%i)\n", commands->command_args[0], i);
		curr_pid = exec_cmd_middle(commands->command_args, pipefd[i - 1],
				pipefd[i], env);
		if (curr_pid == 0)
			return (curr_pid);
		close(pipefd[i - 1][0]);
		close(pipefd[i][1]);
		commands = commands->next;
		i++;
	}
	return (curr_pid);
}

static int	exec_cmd_multi(t_command *commands, char *infile, char *outfile,
		char **env)
{
	int	(*pipefd)[2];
	int	command_count;
	int	curr_pid;

	command_count = count_commands(commands);
	open_pipes(&pipefd, command_count - 1);
	curr_pid = exec_cmd_first(commands->command_args, pipefd[0], infile, env);
	if (curr_pid != 0)
	{
		close(pipefd[0][1]);
		commands = commands->next;
		if (commands->next != NULL)
			curr_pid = exec_cmd_middle_from_parent(commands, pipefd, env);
		if (curr_pid != 0)
		{
			while (commands->next != NULL)
				commands = commands->next;
			curr_pid = exec_cmd_last(commands->command_args,
					pipefd[command_count - 2], outfile, env);
		}
	}
	free(pipefd);
	//ft_printf("ret pid: %i\n", curr_pid);
	return (curr_pid);
}

static void	wait_for_child_processes(int p_count)
{
	int	i;

	i = 0;
	while (i < p_count)
	{
		//ft_printf("awaiting %i / %i..\n", i + 1, p_count);
		wait(NULL);
		//ft_printf("awaited  %i / %i\n", i + 1, p_count);
		i++;
	}
	//ft_printf("awaited all, returning..\n");
}

int	main(int argc, char **argv, char **env)
{
	t_command	*commands;
	int			command_count;
	int			curr_pid;

	check_arg_count(MIN_ARG_COUNT, argc - 1);
	commands = argv_to_commands_list(argc, argv, env);
	handle_here_doc(&commands, argc, argv);
	curr_pid = -1;
	command_count = count_commands(commands);
	if (command_count == 1)
		curr_pid = exec_cmd_single(commands->command_args, argv[1],
				argv[argc - 1], env);
	else
		curr_pid = exec_cmd_multi(commands, argv[1], argv[argc - 1], env);
	if (curr_pid != 0)
	{
		wait_for_child_processes(command_count);
		if (!ft_strncmp(argv[1], HERE_DOC_TEMPFILE,
				ft_strlen(HERE_DOC_TEMPFILE)))
			remove_file(HERE_DOC_TEMPFILE);
	}
	deallocate_commands(&commands);
	//ft_printf("pid: %i ok\n", curr_pid);
	return (0);
}
