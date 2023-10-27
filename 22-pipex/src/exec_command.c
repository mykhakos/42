/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:39:27 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 17:19:43 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_cmd_first(char **cmd_args, int *pipefd, char *infile, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror_with_exit("fork", EXIT_FAILURE);
	}
	if (pid == 0)
	{
		redirect_file_to_stdin(infile);
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if (execve(cmd_args[0], cmd_args, env) == -1)
			perror_with_exit("execve", EXIT_FAILURE);
	}
}

void	exec_cmd_last(char **cmd_args, int *pipefd, char *outfile, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror_with_exit("fork", EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		redirect_stdout_to_file(outfile);
		if (execve(cmd_args[0], cmd_args, env) == -1)
			perror_with_exit("execve", EXIT_FAILURE);
	}
}

void	exec_cmd_middle(char **cmd_args, int *pipefd_in, int *pipefd_out,
		char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror_with_exit("fork", EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(pipefd_in[1]);
		dup2(pipefd_in[0], STDIN_FILENO);
		close(pipefd_in[0]);
		close(pipefd_out[0]);
		dup2(pipefd_out[1], STDOUT_FILENO);
		close(pipefd_out[1]);
		if (execve(cmd_args[0], cmd_args, env) == -1)
			perror_with_exit("execve", EXIT_FAILURE);
	}
}

void	exec_cmd_single(char **cmd_args, char *infile, char *outfile,
		char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror_with_exit("fork", EXIT_FAILURE);
	}
	if (pid == 0)
	{
		redirect_file_to_stdin(infile);
		redirect_stdout_to_file(outfile);
		if (execve(cmd_args[0], cmd_args, env) == -1)
			perror_with_exit("execve", EXIT_FAILURE);
	}
}

int	(*open_pipes(int number))[2]
{
	int	(*pipefd)[2];
	int	i;

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
