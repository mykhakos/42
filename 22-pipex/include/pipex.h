#ifndef PIPEX_H
 #define PIPEX_H

 #include <unistd.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include "../lib/libft/libft.h"

typedef struct s_command
{
    char **command_args;
    struct s_command *next;
} t_command;

char *get_env_var(char *key, char **env);
char *get_exec_file_path(char *file, char **env_paths);
t_command *init_command(char **command_args);
void add_command(t_command **commands, char **command_args);
void append_command(t_command **commands, t_command *command);
void deallocate_commands(t_command **commands);
char **parse_args(char *command, char **env_paths);
char **split_args(char *command_args);
void free_env_paths(char **env_paths);
t_command *argv_to_commands_list(int argc, char **argv, char **env);
void redirect_file_to_stdin(char *file);
void redirect_stdout_to_file(char *file);

#endif