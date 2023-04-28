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

#include "get_next_line.h"

static int	find_newline_start(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

static char	*extract_line(char **remainder)
{
	int		newline_position;
	char	*tmp;
	char	*line;

	line = NULL;
	newline_position = find_newline_start(*remainder);
	if (newline_position >= 0)
	{
		line = ft_substr(*remainder, 0, newline_position);
		tmp = *remainder;
		*remainder = ft_strdup(tmp + newline_position);
		free(tmp);
	}
	return (line);
}

char	*read_and_extract(char **remainder, int fd, int *bytes_read)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	*bytes_read = read(fd, buf, BUFFER_SIZE);
	if (*bytes_read <= 0)
		return (NULL);
	buf[*bytes_read] = '\0';
	if (*remainder)
	{
		tmp = *remainder;
		*remainder = ft_strjoin(tmp, buf);
		free(tmp);
	}
	else
		*remainder = ft_strdup(buf);
	return (extract_line(remainder));
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
	if (!line && remainder[fd])
		line = extract_line(&remainder[fd]);
	if (!line && remainder[fd])
	{
		line = ft_strdup(remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	return (line);
}
