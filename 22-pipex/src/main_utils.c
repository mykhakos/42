#include "../include/pipex.h"

void free_env_paths(char **env_paths)
{
    char **env_paths_ptr;

    env_paths_ptr = env_paths;
    while (*env_paths_ptr != NULL)
    {
        free(*env_paths_ptr);
        env_paths_ptr++;
    }
    free(env_paths);
}

t_command *argv_to_commands_list(int argc, char **argv, char **env)
{
    t_command *commands;
    char **command_args;
	char *env_path_var;
	char **env_paths;
    int i;

    env_path_var = get_env_var("PATH", env);
	env_paths = ft_split(env_path_var, ':');
    if (env_paths == NULL)
    {
        perror("Error splitting PATH");
        exit(1);
    }
    commands = NULL;
    i = 2;
    while (i < argc - 1)
    {
        command_args = parse_args(argv[i], env_paths);
        if (command_args == NULL)
        {
            perror("Error formatting command");
            exit(1);
        }
        add_command(&commands, command_args);
        i++;
    }
    free_env_paths(env_paths);
    return (commands);
}

void redirect_file_to_stdin(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
}

void redirect_stdout_to_file(char *file)
{
    int fd;

    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}