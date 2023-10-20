#include "../include/pipex.h"


void remove_here_doc_from_commands(t_command **commands)
{
    t_command *temp;
    int i;

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

void write_user_input_to_file(int file_fd, char *limiter, int *found_limiter)
{
    char *line;
    int line_len;
    int line_len_no_nl;

    while (1)
    {
        line = get_next_line(STDIN_FILENO);
        if (line == NULL)
            break ;
        line_len = ft_strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n')
            line_len_no_nl = line_len - 1;
        else
            line_len_no_nl = line_len;
        if (ft_strncmp(line, limiter, line_len_no_nl) == 0)
        {
            *found_limiter = 1;
            free(line);
            break ;
        }
        write(file_fd, line, line_len);
        free(line);
    }
}

void read_user_input(char *limiter)
{
    int tempfile_fd;
    int found_limiter;

    tempfile_fd = open("tempfile", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (tempfile_fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    found_limiter = 0;
    write_user_input_to_file(tempfile_fd, limiter, &found_limiter);
    close(tempfile_fd);
    if (!found_limiter)
    {
        ft_printf("warning: here_doc delimited by end-of-file (wanted '%s')\n",
                  limiter);
    }
}

void remove_tempfile(void)
{
    if (unlink("tempfile") != 0)
    {
        perror("unlink");
        exit(EXIT_FAILURE);
    }
}