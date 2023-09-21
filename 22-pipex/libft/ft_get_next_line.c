/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:33:51 by kmykhail          #+#    #+#             */
/*   Updated: 2023/04/28 13:33:55 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_and_free(char **remainder, char **buffer)
{
	char	*tmp;

	if (*remainder)
	{
		tmp = *remainder;
		*remainder = ft_strjoin(tmp, *buffer);
		free(tmp);
		free(*buffer);
	}
	else
	{
		*remainder = ft_strdup(*buffer);
		free(*buffer);
	}
}

static char	*extract_line(char **remainder)
{
	int		newline_position;
	char	*tmp;
	char	*line;

	line = NULL;
	newline_position = ft_find_nl(*remainder);
	if (newline_position >= 0)
	{
		line = ft_substr(*remainder, 0, newline_position);
		tmp = *remainder;
		*remainder = ft_strdup(tmp + newline_position);
		free(tmp);
	}
	return (line);
}

static char	*read_and_extract(char **remainder, int fd, int *bytes_read)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*bytes_read] = '\0';
	join_and_free(remainder, &buffer);
	return (extract_line(remainder));
}

static void	free_remainder(char **remainder)
{
	free(*remainder);
	*remainder = NULL;
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*line;
	static char	*remainder[FD_MAX];

	if (fd < 0 || fd >= FD_MAX)
		return (NULL);
	while (1)
	{
		line = read_and_extract(&remainder[fd], fd, &bytes_read);
		if (line || bytes_read <= 0)
			break ;
	}
	if (bytes_read < 0)
		return (NULL);
	if (line == NULL && remainder[fd])
		line = extract_line(&remainder[fd]);
	if (remainder[fd] && *remainder[fd] == '\0')
		free_remainder(&remainder[fd]);
	if (line == NULL && remainder[fd])
	{
		line = ft_strdup(remainder[fd]);
		free_remainder(&remainder[fd]);
	}
	return (line);
}
