#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include "libft/libft.h"

char	*get_env_var(char *key, char **env)
{
	int		key_len;

	key_len = ft_strlen(key);
    while (*env != NULL)
    {
        if (ft_strncmp(*env, key, key_len) == 0 && (*env)[key_len] == '=')
        {
			return (*env + key_len + 1);
        }
        env++;
    }
    return NULL;
}

char	*concat_path(char *prefix, char *path)
{
	char    *tmp;
	char	*full_path;

	tmp = ft_strjoin(prefix, "/");
	full_path = ft_strjoin(tmp, path);
	free(tmp);
	return (full_path);
}


char*	get_full_path(char *path, char **env)
{
	char	*full_path;
	char	*env_path_var;
	char	**env_paths;
	int		i;
	int		found;

	env_path_var = get_env_var("PATH", env);
	env_paths = ft_split(env_path_var, ':');
	found = 0;
	i = 0;
	while (env_paths[i] != NULL)
	{
		if (!found)
		{
			full_path = concat_path(env_paths[i], path);
			if (access(full_path, X_OK) == 0)
			{
				found = 1;
			}
			else
			{
				free(full_path);
			}
		}
		free(env_paths[i]);
		i++;
	}
	free(env_paths);
	if (found)
	{
		printf("%s\n", full_path);
		return (full_path);
	}
	return (NULL);
}


char **get_func_params(int func_no, char **argv)
{
	char	*func_call;
	char	**func_args;

	func_call = argv[func_no];
	func_args = ft_split(func_call, ' '); 
	return (func_args);
}

void ft_perror(char *msg)
{
    if (msg)
    {
        perror(msg);
    }
    else
    {
        perror("Error");
    }
    exit (1);
}

void exec_func(int func_no, char* argv[], char* envp[], int in_fd, int out_fd) {
    if (dup2(in_fd, STDIN_FILENO) == -1)
        ft_perror("Could not redirect STDIN fd to the specified fd.");
    if (dup2(out_fd, STDOUT_FILENO) == -1)
        ft_perror("Could not redirect STDOUT fd to the specified fd.");
    char **params = get_func_params(func_no, argv);
    char *path = get_full_path(params[0], envp);
    params[0] = path;
    if (execve(path, params, envp) == -1)
        ft_perror("Could not execute the command.");
}

void execute_funcs(int argc, char* argv[], char *envp[])
{
    int fd[2];
    int file;
    pid_t pid1, pid2;

    if (pipe(fd) == -1)
        ft_perror("Could not open a pipe.");
    
    pid1 = fork();
    if (pid1 < 0)
        ft_perror("Could not fork a proccess.");
    if (pid1 == 0)
    {
        close(fd[0]);
        file = open(argv[1], O_RDONLY);
        if (!file)
            ft_perror("Could not open the input file.");
        exec_func(2, argv, envp, file, fd[1]);
        close(fd[1]);
    }

    pid2 = fork();
    if (pid2 < 0)
        ft_perror("Could not fork a proccess.");
    if (pid2 == 0)
    {
        close(fd[1]);
        file = open(argv[argc - 1], O_WRONLY);
        if (!file)
            ft_perror("Could not open the output file.");
        exec_func(argc - 2, argv, envp, fd[0], file);
        close(fd[0]);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}



int main(int argc, char* argv[], char *envp[])
{
    if (argc != 5)
	{
		ft_perror("The base version can only handle two commands.");
	}
	execute_funcs(argc, argv, envp);
    return 0;
}