/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:54:27 by kmykhail          #+#    #+#             */
/*   Updated: 2023/10/27 17:05:41 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	count_arg_len(char *str, char delimiter)
{
	int		len;
	char	current_quote;

	len = 0;
	current_quote = '\0';
	while (str[len] != '\0')
	{
		if (!current_quote && str[len] == delimiter)
			break ;
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

static char	*get_next_arg(char **command_args, char current_quote)
{
	char	*arg;
	int		len;

	if (*command_args[0] == '\'' || *command_args[0] == '"')
	{
		len = count_arg_len(*command_args + 1, current_quote);
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
		len = count_arg_len(*command_args, ' ');
		arg = ft_substr(*command_args, 0, len);
		*command_args += len;
		return (arg);
	}
}

static int	count_args(char *command_args)
{
	int		count;
	char	*arg;

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

static char	**split_args(char *command_args)
{
	char	**args;
	char	*command_args_ptr;
	int		i;

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

char	**parse_args(char *command, char **env_paths)
{
	char	**command_args;
	char	*formatted;

	command_args = split_args(command);
	formatted = get_exec_file_path(command_args[0], env_paths);
	if (formatted != NULL)
	{
		free(command_args[0]);
		command_args[0] = formatted;
	}
	return (command_args);
}
