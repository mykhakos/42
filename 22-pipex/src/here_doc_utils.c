/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:51:41 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 17:12:10 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	remove_here_doc_from_commands(t_command **commands)
{
	t_command	*temp;
	int			i;

	if (*commands == NULL)
		return ;
	temp = *commands;
	*commands = (*commands)->next;
	i = 0;
	while (temp->command_args[i] != NULL)
	{
		free(temp->command_args[i]);
		i++;
	}
	free(temp->command_args);
	free(temp);
}

int	is_limiter(char *limiter, char *line, int line_len)
{
	int	limiter_len;

	if (line_len > 0 && line[line_len - 1] == '\n')
		line_len = line_len - 1;
	limiter_len = ft_strlen(limiter);
	if ((ft_strncmp(line, limiter, line_len) == 0) && (limiter_len == line_len))
		return (1);
	return (0);
}

void	write_user_input_to_file(int file_fd, char *limiter, int *found_limiter)
{
	char	*line;
	int		line_len;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		line_len = ft_strlen(line);
		if (is_limiter(limiter, line, line_len))
		{
			*found_limiter = 1;
			free(line);
			break ;
		}
		write(file_fd, line, line_len);
		free(line);
	}
}

void	read_and_save_user_input(char *filename, char *limiter)
{
	int	file_fd;
	int	found_limiter;

	file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_fd == -1)
		perror_with_exit("open", EXIT_FAILURE);
	found_limiter = 0;
	write_user_input_to_file(file_fd, limiter, &found_limiter);
	close(file_fd);
	if (!found_limiter)
	{
		ft_printf("warning: here_doc delimited by end-of-file (wanted '%s')\n",
			limiter);
	}
}

void	remove_file(char *filename)
{
	if (unlink(filename) != 0)
		perror_with_exit(filename, EXIT_FAILURE);
}
