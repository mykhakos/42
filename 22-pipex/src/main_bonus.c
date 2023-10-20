#include "../include/pipex.h"

void exec_cmd_first(char **cmd_args, int *pipefd, char *infile, char **env)
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

void exec_cmd(char **cmd_args, int *pipefd_in, int *pipefd_out, char **env)
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
        close(pipefd_in[1]);
        dup2(pipefd_in[0], STDIN_FILENO);
        close(pipefd_in[0]);
        close(pipefd_out[0]);
        dup2(pipefd_out[1], STDOUT_FILENO);
        close(pipefd_out[1]);
        if (execve(cmd_args[0], cmd_args, env) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
}

void exec_cmd_last(char **cmd_args, int *pipefd, char *outfile, char **env)
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

void exec_cmd_single(char **cmd_args, char *infile, char *outfile, char **env)
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
        redirect_stdout_to_file(outfile);
        if (execve(cmd_args[0], cmd_args, env) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
}

int (*open_pipes(int number))[2]
{
    int (*pipefd)[2];
    int i;

    pipefd = malloc(number * sizeof(*pipefd));
    if (!pipefd) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
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
    return (pipefd);
}



int main(int argc, char **argv, char **env)
{
    t_command *commands;
    t_command *commands_ptr;
    int command_count;
    int (*pipefd)[2];
    int i;
    

    if (argc < 4)
    {
        ft_printf("Too few args (expected at least 3, got %i).\n", argc - 1);
        exit(EXIT_SUCCESS);        
    }
    commands = argv_to_commands_list(argc, argv, env);
    commands_ptr = commands;
    if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
    {
        read_user_input(argv[2]);
        remove_here_doc_from_commands(&commands);
        argv[1] = "tempfile";
    }
    command_count = count_commands(commands);
    if (command_count == 1)
    {
        exec_cmd_single(commands->command_args, argv[1], argv[argc - 1], env);
    }
    else
    {
        pipefd = open_pipes(command_count - 1);
        exec_cmd_first(commands_ptr->command_args, pipefd[0], argv[1], env);
        close(pipefd[0][1]);
        commands_ptr = commands_ptr->next;
        i = 1;
        while (commands_ptr->next != NULL)
        {
            exec_cmd(commands_ptr->command_args, pipefd[i-1], pipefd[i], env);
            close(pipefd[i-1][0]);
            close(pipefd[i][1]);
            commands_ptr = commands_ptr->next;
            i++;
        }
        exec_cmd_last(commands_ptr->command_args, pipefd[i-1], argv[argc - 1], env);
        free(pipefd);
    }
    i = 0;
    while (i < command_count)
    {
        printf("waiting %i / %i\n", i +1 , command_count);
        wait(NULL);
        i++;
    }
    deallocate_commands(&commands);
    if (!ft_strncmp(argv[1], "tempfile", ft_strlen("tempfile")))
    {
        remove_tempfile();
    }
    return (0);
}
