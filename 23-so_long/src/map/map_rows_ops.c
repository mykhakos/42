/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rows_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:27:44 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 19:28:39 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_map_row	*init_row(char *row_chars)
{
	t_map_row	*row;

	row = malloc(sizeof(t_map_row));
	if (!row)
		return (NULL);
	row->row = row_chars;
	row->next = NULL;
	return (row);
}

void	append_row(t_map_row **rows, char *new_row_chars)
{
	t_map_row	*new_row;
	t_map_row	*last_row;

	new_row = init_row(new_row_chars);
	last_row = *rows;
	if (last_row == NULL)
	{
		*rows = new_row;
	}
	else
	{
		while (last_row->next != NULL)
			last_row = last_row->next;
		last_row->next = new_row;
	}
}

void	deallocate_rows(t_map_row **rows)
{
	t_map_row	*current;
	t_map_row	*next;

	current = *rows;
	while (current != NULL)
	{
		next = current->next;
		free(current->row);
		free(current);
		current = next;
	}
	*rows = NULL;
}

int	get_row_count(t_map_row *rows)
{
	int	count;

	count = 0;
	while (rows != NULL)
	{
		count++;
		rows = rows->next;
	}
	return (count);
}

t_map_row	*read_map_rows_from_file(char *map_file)
{
	int			map_fd;
	char		*row_chars;
	t_map_row	*map_rows;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		perror_and_exit(EXIT_FAILURE, "open");
	row_chars = get_next_line(map_fd);
	if (!row_chars)
	{
		close(map_fd);
		ft_printf("%s map file is empty.\n");
		exit(EXIT_FAILURE);
	}
	map_rows = NULL;
	while (row_chars != NULL)
	{
		append_row(&map_rows, ft_strtrim(row_chars, "\n"));
		free(row_chars);
		row_chars = get_next_line(map_fd);
	}
	close(map_fd);
	return (map_rows);
}
