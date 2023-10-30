/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:39:27 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 22:06:30 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_cmd_first(char **cmd_args, int *pipefd, char *infile, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
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
}

void	exec_cmd_last(char **cmd_args, int *pipefd, char *outfile, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
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
}
