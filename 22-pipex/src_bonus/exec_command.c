/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:39:27 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/31 21:13:31 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	exec_cmd_first(char **cmd_args, int *pipefd, char *infile, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (pid);
	}
	if (pid == 0)
	{
		if (redirect_file_to_stdin(infile) != -1)
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[1]);
			if (execve(cmd_args[0], cmd_args, env) == -1)
				perror("execve");
		}
	}
	return (pid);
}

int	exec_cmd_last(char **cmd_args, int *pipefd, char *outfile, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (pid);
	}
	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		if (redirect_stdout_to_file(outfile) != -1)
		{
			if (execve(cmd_args[0], cmd_args, env) == -1)
				perror("execve");
		}
	}
	return (pid);
}

int	exec_cmd_middle(char **cmd_args, int *pipefd_in, int *pipefd_out,
		char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (pid);
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
			perror("execve");
	}
	return (pid);
}

int	exec_cmd_single(char **cmd_args, char *infile, char *outfile, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (pid);
	}
	if (pid == 0)
	{
		if (redirect_file_to_stdin(infile) == -1)
			return (pid);
		if (redirect_stdout_to_file(outfile) == -1)
			return (pid);
		if (execve(cmd_args[0], cmd_args, env) == -1)
			perror("execve");
	}
	return (pid);
}

void	open_pipes(int (**pipefd_ptr)[2], int number)
{
	int	i;
	int	(*pipefd)[2];

	pipefd = malloc(number * sizeof(*pipefd));
	if (!pipefd)
		perror_with_exit("malloc", EXIT_FAILURE);
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
	*pipefd_ptr = pipefd;
}
