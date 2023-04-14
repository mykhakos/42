#include "get_next_line.h"
#include <stdio.h>


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

static int	update_remainder(char **remainder, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	buf[bytes_read] = '\0';
	if (*remainder)
	{
		tmp = *remainder;
		*remainder = ft_strjoin(tmp, buf);
		free(tmp);
	}
	else
	{
		*remainder = ft_strdup(buf);
	}
	return (bytes_read);
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

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*line;
	static char	*remainder[FD_MAX];

	if (fd < 0 || fd >= FD_MAX)
		return (NULL);
	while ((bytes_read = update_remainder(&remainder[fd], fd)) > 0)
	{
		if ((line = extract_line(&remainder[fd])))
			return (line);
	}
	if (bytes_read < 0)
		return (NULL);
	if ((line = extract_line(&remainder[fd])))
		return (line);
	if (remainder[fd])
	{
		line = ft_strdup(remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (line);
	}
	return (NULL);
}
