#include "../include/pipex.h"

void exec_cmd1(char **cmd_args, int *pipefd, char *infile, char **env)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        redirect_file_to_stdin(infile);
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        if (execve(cmd_args[0], cmd_args, env) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
}

void exec_cmd2(char **cmd_args, int *pipefd, char *outfile, char **env)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        redirect_stdout_to_file(outfile);
        if (execve(cmd_args[0], cmd_args, env) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    t_command *commands;
    t_command *commands_ptr;
    int pipefd[2];

    if (argc != 5)
    {
        ft_printf("Invalid arg count (expected 4, got %i).\n", argc - 1);
        exit(EXIT_SUCCESS);        
    }
    commands = argv_to_commands_list(argc, argv, env);
    commands_ptr = commands;
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    exec_cmd1(commands_ptr->command_args, pipefd, argv[1], env);
    commands_ptr = commands_ptr->next;
    exec_cmd2(commands_ptr->command_args, pipefd, argv[argc - 1], env);
    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);
    deallocate_commands(&commands);
    return (0);
}
