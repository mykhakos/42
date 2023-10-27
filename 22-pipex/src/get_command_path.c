/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:50:47 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 17:10:36 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*join_path(char *prefix, char *path)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(prefix, "/");
	full_path = ft_strjoin(tmp, path);
	free(tmp);
	return (full_path);
}

char	*get_exec_file_path(char *file, char **env_paths)
{
	char	*full_path;
	int		i;

	full_path = join_path(".", file);
	if (access(full_path, F_OK) == 0)
		return (full_path);
	else
	{
		i = 0;
		while (env_paths[i] != NULL)
		{
			full_path = join_path(env_paths[i], file);
			if (access(full_path, F_OK) == 0)
				return (full_path);
			else
			{
				free(full_path);
				full_path = NULL;
			}
			i++;
		}
	}
	return (NULL);
}
