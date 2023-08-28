#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include "libft/libft.h"



void ft_perror_and_exit(char *msg)
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

void close_fd(int *fd)
{
	if (*fd != -1)
	{
		close(*fd);
		*fd = -1;
	}
}

void close_and_free_pipes(int **pipes, int n)
{
	int i = 0;

	while (i < n || (n == -1 && pipes[i] != NULL))
	{
		if (pipes[i]) 
		{
			close_fd(&pipes[i][0]);
			close_fd(&pipes[i][1]);
			free(pipes[i]);
		}
		i++;
	}
	free(pipes);
}


int	**open_pipes(int n)
{
	int	i;
	int	**pipes;

	pipes = malloc(n * sizeof(int *) + 1);
	if (!pipes)
		ft_perror_and_exit("Could not allocate memory for pipes.");
	i = 0;
	while (i < n)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i] || pipe(pipes[i]) == -1)
		{
			close_and_free_pipes(pipes, i);
			ft_perror_and_exit("Could not allocate memory or open a pipe.");
		}
		i++;
	}
	pipes[i] = NULL;
	return (pipes);
}


void free_processes(int *pids, int n)
{
    int i;
	int status;

	i = 0;
	while (i < n)
	{
		waitpid(pids[i], &status, 0);
		i++;
	}
    free(pids);
}


int	*spawn_processes(int n)
{
	int	i;
	int	*pids;

	pids = malloc(n * sizeof(int));
	if (!pids)
		ft_perror_and_exit("Could not allocate memory for process ids.");
	i = 0;
	while (i < n)
	{
		pids[i] = fork();
		if (pids[i] < 0)
		{
			free_processes(pids, i);
			ft_perror_and_exit("Could not fork a process.");
		}
		if (pids[i] == 0)
			exit(0);
		i++;
	}
	return (pids);
}

int dup_read_and_close(int pipe_no, int **pipes)
{
	close(pipes[pipe_no - 1][1]);
	if (dup2(pipes[pipe_no - 1][0], STDIN_FILENO) == -1)
		return (-1);
	close(pipes[pipe_no - 1][0]);
    return 0;
}

int dup_write_and_close(int pipe_no, int **pipes)
{
	close(pipes[pipe_no][0]);
	if (dup2(pipes[pipe_no][1], STDOUT_FILENO) == -1)
		return (-1);
	close(pipes[pipe_no][1]);
    return 0;
}

void connect_processes(int **pipes, int *pids, int n)
{
    int i;

	i = 0;
    while (i < n)
    {
        if (pids[i] == 0)
        {
            if (i != 0 && dup_read_and_close(i, pipes) == -1)
			{
				close_and_free_pipes(pipes, -1);
				ft_perror("Could not redirect stdin.");
				exit(1);
			}
            if (i != n - 1 && dup_write_and_close(i, pipes) == -1)
			{
				ft_perror("Could not redirect stdout.");
				exit(1);
			}
            return;
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
        i++;
    }
}



void connect_processes()
{
		i = 0;
	while (i < n)
	{
		pids[i] = malloc(sizeof(int));
		pids[i] = fork();
		if (pids[i] < 0)
			ft_perror("Could not fork a proccess.");
		if (pids[i] == 0)
		{
			j = 0;
			while (j < n + 1)
			{
				if (i != j)
					close(pipes[i][0]);
				if (i + 1 != j)
					close(pipes[j][1]);
			}
			return (0);
		}
			
		i++;
	}
}

void execute_funcs(int argc, char* argv[], char *envp[])
{
	
	int		file;
    int		**pipes;
    pid_t	**pids;


	pipes = open_pipes(argc - 2);
    pids = spawn_processes(argc - 3);


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