#include "../include/pipex.h"

#include <stdio.h>


int count_len(char *str, char delimiter)
{
    int len = 0;
    char current_quote;

    len = 0;
    current_quote = '\0';
    while (str[len] != '\0')
    {
        if (!current_quote && str[len] == delimiter)
            break;
        if (str[len] == '\'' || str[len] == '"')
        {
            if (!current_quote)
                current_quote = str[len];
            else if (str[len] == current_quote)
                current_quote = '\0';
        }
        len++;
    }
    return (len);
}


char *get_next_arg(char **command_args, char current_quote)
{
    char *arg;
    int len;

    if (*command_args[0] == '\'' || *command_args[0] == '"') 
    {
        len = count_len(*command_args + 1, current_quote);
        if ((*command_args)[len + 1] == current_quote) 
        {
            arg = ft_substr(*command_args + 1, 0, len);
            *command_args += len + 2;
        } 
        else 
        {
            arg = ft_substr(*command_args, 0, len + 1);
            *command_args += len + 1;
        }
        return (arg);
    } 
    else 
    {
        len = count_len(*command_args, ' ');
        arg = ft_substr(*command_args, 0, len);
        *command_args += len;
        return (arg);
    }
}

// make static later
int count_args(char *command_args)
{
    int count;
    char *arg;

    count = 0;
    while (*command_args != '\0') 
    {
        while (*command_args == ' ')
            command_args++;
        arg = get_next_arg(&command_args, command_args[0]);
        free(arg);
        count++;
    }
    return (count);
}


char **split_args(char *command_args) 
{
    char **args;
    char *command_args_ptr;
    int i;

    command_args = ft_strtrim(command_args, " ");
    command_args_ptr = command_args;
    args = malloc(sizeof(char *) * (count_args(command_args) + 1));
    if (!args)
        exit(1);
    i = 0;
    while (*command_args != '\0') 
    {
        while (*command_args == ' ')
            command_args++;
        args[i] = get_next_arg(&command_args, command_args[0]);
        i++;
    }
    args[i] = NULL;
    free(command_args_ptr);
    return (args);
}


/*
void print_and_free_str_arr(char **str_arr)
{
    char **original_ptr = str_arr;  // Save the original pointer for later freeing
    
    while (*str_arr != NULL)
    {
        printf("%s\n", *str_arr);
        free(*str_arr);
        str_arr++;
    }
    free(original_ptr);
}

int main() 
{
    //Test cases
    char *tests[] = {
        "one two three",
        "  a    lot '    of   spaces'  ",
        "one 'two three'",
        "'startquote",
        "'start quote with space",
        "endquote'",
        "endquote with space'",
        "middle'quote",
        "middle quote 'with space",
        "middle quote'in word",
        "quotes'without spaces'",
        "'' '' ''",
        "",
        "\"one   two\" three   four'five six'",
        NULL
    };
    
    int i = 0;
    while (tests[i])
    {
        char **parsed_args = parse_args(tests[i]);
        print_and_free_str_arr(parsed_args);
        printf("%s\n", "---------");
        i++;
    }
    return 0;
}
*/