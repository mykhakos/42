
char *_remove_internal_quotes(char *arg) {
    char *cleaned;
    char quote_char;
    int i;
    int j;
    int quote_opened;

    cleaned = malloc(ft_strlen(arg) + 1);
    if (!cleaned)
        exit(1);

    quote_char = '\0';
    quote_opened = 0;
    i = 0;
    j = 0;

    while (arg[i] != '\0')
    {
        if ((arg[i] == '\'' || arg[i] == '"') && !quote_char)
        {
            quote_char = arg[i];
            quote_opened = 1;
        }
        else if (arg[i] == quote_char)
        {
            quote_opened = 0;
            quote_char = '\0';
        }
        else
            cleaned[j++] = arg[i];
        i++;
    }
    
    if (quote_opened)
        cleaned[j++] = quote_char;

    cleaned[j] = '\0';

    free(arg);
    return cleaned;
}




/*
char **__parse_args(char *command_args)
{
    char current_quote;
    char **args;
    int len;
    int i;

    args = malloc(sizeof(char *) * (count_args(command_args) + 1));
    if (!args)
        exit(1);
    i = 0;
    while (*command_args != '\0')
    {
        while (*command_args == ' ')
            command_args += 1;
        if (*command_args == '\'' || *command_args == '"')
        {
            current_quote = *command_args;
            command_args += 1;
            len = count_len(command_args, current_quote);
            args[i] = ft_substr(command_args, 0, len);
            command_args += len + 1;
            i++;
        }
        else
        {
            len = count_len(command_args, ' ');
            args[i] = ft_substr(command_args, 0, len);
            command_args += len;
            i++;            
        }
    }
    args[i] = NULL;
    return (args);
}
*/



//  WORKS, BUT IS LONG
char **_parse_args(char *command_args) 
{
    char **args;
    char current_quote;
    int inside_quote;
    int len;
    int i;

    args = malloc(sizeof(char *) * (count_args(command_args) + 1));
    if (!args)
        exit(1);
    inside_quote = 0;
    i = 0;
    while (*command_args != '\0') 
    {
        while (*command_args == ' ' && !inside_quote)
            command_args++;
        if (*command_args == '\'' || *command_args == '"') 
        {
            current_quote = *command_args;
            len = count_len(command_args + 1, current_quote);
            if (command_args[len + 1] == current_quote) 
            {
                args[i] = ft_substr(command_args + 1, 0, len);
                command_args += len + 2;
            }
            else
            {
                args[i] = ft_substr(command_args, 0, len + 1);
                command_args += len + 1;
            }
            i++;
        } 
        else 
        {
            len = count_len(command_args, ' ');
            args[i] = ft_substr(command_args, 0, len);
            command_args += len;
            i++;
        }
    }
    args[i] = NULL;
    return (args);
}


// old implemetation, probably wont need
int _count_args(char *command_args)
{
    int count;
    int is_inside_quote;

    count = 0;
    is_inside_quote = 0;
    while (*command_args != '\0')
    {
        while (*command_args == ' ' && !is_inside_quote)
            command_args++;
        if (*command_args == '\'' || *command_args == '"')
        {
            is_inside_quote = !(is_inside_quote);
            if (is_inside_quote)
                count++;
            command_args++;
        }
        else if (!is_inside_quote)
        {
            count++;
            while (*command_args && *command_args != ' ')
                command_args++;
        }
        else
            command_args++;
    }
    return (count);
}