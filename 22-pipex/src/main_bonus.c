/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:14 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/24 20:53:19 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

#define MIN_ARG_COUNT 3
#define TEMPFILE "tempfile"


static void	check_arg_count(int arg_count)
{
	if (arg_count != MIN_ARG_COUNT)
	{
		dup2(STDOUT_FILENO, STDERR_FILENO);
		ft_printf("Too few args (expected at least %i, got %i).\n",
			MIN_ARG_COUNT, arg_count);
		exit(EXIT_FAILURE);
	}
}

int (*open_pipes(int number))[2]
{
	int(*pipefd)[2];
	int i;

	pipefd = malloc(number * sizeof(*pipefd));
	if (!pipefd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < number)
	{
		if (pipe(pipefd[i]) == -1)
		{
			perror("pipe");
			free(pipefd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (pipefd);
}

int	main(int argc, char **argv, char **env)
{
	t_command	*commands;
	t_command	*commands_ptr;
	int			command_count;
	int			i;
	int			(*pipefd)[2];

	check_arg_count(argc - 1);
	commands = argv_to_commands_list(argc, argv, env);
	commands_ptr = commands;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
	{
		read_and_save_user_input(TEMPFILE, argv[2]);
		remove_here_doc_from_commands(&commands);
		argv[1] = TEMPFILE;
	}
	command_count = count_commands(commands);
	if (command_count == 1)
	{
		exec_cmd_single(commands->command_args, argv[1], argv[argc - 1], env);
	}
	else
	{
		pipefd = open_pipes(command_count - 1);
		exec_cmd_first(commands_ptr->command_args, pipefd[0], argv[1], env);
		close(pipefd[0][1]);
		commands_ptr = commands_ptr->next;
		i = 1;
		while (commands_ptr->next != NULL)
		{
			exec_cmd_middle(commands_ptr->command_args, pipefd[i - 1],
				pipefd[i], env);
			close(pipefd[i - 1][0]);
			close(pipefd[i][1]);
			commands_ptr = commands_ptr->next;
			i++;
		}
		exec_cmd_last(commands_ptr->command_args, pipefd[i - 1], argv[argc - 1],
			env);
		free(pipefd);
	}
	i = 0;
	while (i < command_count)
	{
		wait(NULL);
		i++;
	}
	deallocate_commands(&commands);
	if (!ft_strncmp(argv[1], TEMPFILE, ft_strlen(TEMPFILE)))
	{
		remove_tempfile(TEMPFILE);
	}
	return (0);
}
