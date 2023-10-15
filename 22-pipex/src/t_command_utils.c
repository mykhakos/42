#include "../include/pipex.h"

t_command *init_command(char **command_args)
{
    t_command *command;

    command = malloc(sizeof(t_command));
    if (!command)
        exit(1);
    command->command_args = command_args;
    command->next = NULL;
    return (command);
}

void add_command(t_command **commands, char **command_args)
{
    t_command *command;
    t_command *last;

    if (*commands == NULL)
    {
        *commands = init_command(command_args);
    }
    else
    {
        last = *commands;
        while (last->next != NULL)
        {
            last = last->next;
        }
        command = init_command(command_args);
        last->next = command;
    }
}

void append_command(t_command **commands, t_command *command)
{
    t_command *last;

    if (*commands == NULL)
    {
        *commands = command;
    }
    else
    {
        last = *commands;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = command;
    }
}


void deallocate_commands(t_command **commands)
{
    t_command *current;
    t_command *temp;
    int i;

    current = *commands;
    while (current != NULL)
    {
        if (current->command_args != NULL)
        {
            i = 0;
            while (current->command_args[i] != NULL)
            {
                free(current->command_args[i]);
                i++;
            }
            free(current->command_args);
        }
        temp = current;
        current = current->next;
        free(temp);
    }
    *commands = NULL;
}