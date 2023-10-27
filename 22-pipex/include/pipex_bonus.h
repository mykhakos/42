/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:00:18 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 23:05:53 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
void		redirect_file_to_stdin(char *file);
void		redirect_stdout_to_file(char *file);
void		remove_here_doc_from_commands(t_command **commands);
void		read_and_save_user_input(char *filename, char *limiter);
void		remove_file(char *filename);
void		exec_cmd_first(char **cmd_args, int *pipefd,
				char *infile, char **env);
void		exec_cmd_last(char **cmd_args, int *pipefd,
				char *outfile, char **env);
void		exec_cmd_middle(char **cmd_args, int *pipefd_in,
				int *pipefd_out, char **env);
void		exec_cmd_single(char **cmd_args, char *infile,
				char *outfile, char **env);
void		open_pipes(int (**pipefd_ptr)[2], int number);
#endif