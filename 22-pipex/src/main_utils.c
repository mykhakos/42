/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:37 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/24 20:40:15 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void perror_with_exit(char *msg, int errcode)
{
	perror(msg);
	exit(errcode);
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
			perror_with_exit("Error formatting command", EXIT_FAILURE);
		add_command(&commands, command_args);
		i++;
	}
	free_env_paths(env_paths);
	return (commands);
}

void	redirect_file_to_stdin(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror_with_exit(file, EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	redirect_stdout_to_file(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		perror_with_exit(file, EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
