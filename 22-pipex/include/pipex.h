/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:13:20 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 22:18:42 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_command
{
	char				**command_args;
	struct s_command	*next;
}						t_command;

void		perror_with_exit(char *msg, int errcode);
char		*get_exec_file_path(char *file, char **env_paths);
t_command	*init_command(char **command_args);
void		add_command(t_command **commands, char **command_args);
int			count_commands(t_command *commands);
void		deallocate_commands(t_command **commands);
char		**parse_args(char *command, char **env_paths);
char		**extract_env_paths(char **env);
void		free_env_paths(char **env_paths);
t_command	*argv_to_commands_list(int argc, char **argv,
				char **env);
int			redirect_file_to_stdin(char *file);
int			redirect_stdout_to_file(char *file);
void		exec_cmd_first(char **cmd_args, int *pipefd,
				char *infile, char **env);
void		exec_cmd_last(char **cmd_args, int *pipefd,
				char *outfile, char **env);
#endif