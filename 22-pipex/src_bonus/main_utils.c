/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:37 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 22:18:38 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	perror_with_exit(char *msg, int errcode)
{
	perror(msg);
	exit(errcode);
}

void	check_arg_count(int expected_arg_count, int actual_arg_count)
{
	if (actual_arg_count < expected_arg_count)
	{
		dup2(STDOUT_FILENO, STDERR_FILENO);
		ft_printf("Too few args (expected at least %i, got %i).\n",
			expected_arg_count, actual_arg_count);
		exit(EXIT_FAILURE);
	}
}

t_command	*argv_to_commands_list(int argc, char **argv, char **env)
{
	t_command	*commands;
	char		**command_args;
	char		**env_paths;
	int			i;

	env_paths = extract_env_paths(env);
	commands = NULL;
	i = 2;
	while (i < argc - 1)
	{
		command_args = parse_args(argv[i], env_paths);
		if (command_args == NULL)
		{
			deallocate_commands(&commands);
			perror_with_exit("Error formatting command", EXIT_FAILURE);
		}
		add_command(&commands, command_args);
		i++;
	}
	free_env_paths(env_paths);
	return (commands);
}

int	redirect_file_to_stdin(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirect_stdout_to_file(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
