#include "../include/pipex.h"

char	*join_path(char *prefix, char *path)
{
	char    *tmp;
	char	*full_path;

	tmp = ft_strjoin(prefix, "/");
	full_path = ft_strjoin(tmp, path);
	free(tmp);
	return (full_path);
}

char	*get_env_var(char *key, char **env)
{
	int		key_len;

	key_len = ft_strlen(key);
    while (*env != NULL)
    {
        if (ft_strncmp(*env, key, key_len) == 0 && (*env)[key_len] == '=')
			return (*env + key_len + 1);
        env++;
    }
    return (NULL);
}

char *get_exec_file_path(char *file, char **env_paths)
{
    char	*full_path;
    int     i;

    if (access(file, F_OK) == 0)
    {
        return (file);
    }
    i = 0;
    while (env_paths[i] != NULL)
    {
        full_path = join_path(env_paths[i], file);
        if (access(full_path, F_OK) == 0)
        {
            return (full_path);
        }
        else
        {
            free(full_path);
            full_path = NULL;
        }
        i++;
    }
	return (NULL);
}

char **parse_args(char *command, char **env_paths)
{
    char **command_args;
    char *formatted;
    
    command_args = split_args(command);
    formatted = get_exec_file_path(command_args[0], env_paths);
    if (formatted == NULL)
    {
        //perror("Invalid command");
        //exit(1);
        return (command_args); // dunno if leave as-is or raise an error right away
    }
    free(command_args[0]);
    command_args[0] = formatted;
    return (command_args);
}


/*
char **_parse_command(char *command, char **env_paths)
{
    char **command_split;
    char *formatted;
    int i;
    
    command_split = parse_args(command);
    i = 0;
    while (command_split[i] != NULL)
    {
        formatted = ft_strtrim(command_split[i], "\'\" \t\n");
        free(command_split[i]);
        command_split[i] = formatted;
        i++;
    }
    formatted = get_exec_file_path(command_split[0], env_paths);
    free(command_split[0]);
    command_split[0] = formatted;
    return (command_split);
}
*/