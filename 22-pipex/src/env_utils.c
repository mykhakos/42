/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:32:01 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 17:06:42 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*get_env_var(char *key, char **env)
{
	int	key_len;

	key_len = ft_strlen(key);
	while (*env != NULL)
	{
		if (ft_strncmp(*env, key, key_len) == 0 && (*env)[key_len] == '=')
			return (*env + key_len + 1);
		env++;
	}
	return (NULL);
}

char	**extract_env_paths(char **env)
{
	char	*env_path_var;
	char	**env_paths;

	env_path_var = get_env_var("PATH", env);
	env_paths = ft_split(env_path_var, ':');
	if (env_paths == NULL)
		perror_with_exit("Error splitting PATH", EXIT_FAILURE);
	return (env_paths);
}

void	free_env_paths(char **env_paths)
{
	char	**env_paths_ptr;

	env_paths_ptr = env_paths;
	while (*env_paths_ptr != NULL)
	{
		free(*env_paths_ptr);
		env_paths_ptr++;
	}
	free(env_paths);
}
