#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../libft/libft.h"


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

char*	get_exec_file_path(char *file, char **env)
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
			full_path = concat_path(env_paths[i], file);
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
		return (full_path);
	return (NULL);
}





void exec_file(char *file, char **argv, const char *envp[])
{
	char	*env_var_path;
	char	*file_path;
	char	**file_params;

	if (access(file, X_OK) != 0)
	{
		env_var_path = get_env_var("PATH", envp);
		free(file);
		file_path = get_exec_file_path(file, evnp);
		if (!file_path)
		{
			ft_printf("Cound not find the file \"%s\"", file);
			exit(1);
		}
	}
    if (execve(file_params[0], file_params, envp) == -1)
	{
		ft_perror("Could not execute the command.");
	}
        

	

    
    char *path = get_full_path(params[0], envp);
    params[0] = path;

}