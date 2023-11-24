/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:27:28 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 20:52:01 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_map_pos	*init_map_pos(void)
{
	t_map_pos	*pos;

	pos = malloc(sizeof(t_map_pos));
	if (!pos)
		return (NULL);
	pos->col = 0;
	pos->row = 0;
	return (pos);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->layout = NULL;
	map->row_count = 0;
	map->col_count = 0;
	map->collectibles_count = 0;
	map->player_dir = E;
	map->player_pos = init_map_pos();
	map->exit = init_map_pos();
	return (map);
}

static char	**create_map_layout(t_map_row *rows, int row_count)
{
	char		**layout;
	int			row;

	layout = malloc(sizeof(char *) * row_count);
	if (!layout)
		return (NULL);
	row = 0;
	while (row < row_count)
	{
		layout[row] = ft_strdup(rows->row);
		row++;
		rows = rows->next;
	}
	return (layout);
}

static void	create_and_check_map_layout(t_map **map, t_map_row **map_rows)
{
	t_map_errcode	errcode;
	t_map_row		*map_rows_ptr;

	map_rows_ptr = *map_rows;
	errcode = check_map_chars(*map, map_rows_ptr);
	if (errcode)
	{
		deallocate_rows(map_rows);
		free_map(map);
		put_map_err_and_exit(errcode);
	}
	(*map)->layout = create_map_layout(map_rows_ptr, (*map)->row_count);
	if (!((*map)->layout))
	{
		deallocate_rows(map_rows);
		free_map(map);
		perror_and_exit(EXIT_FAILURE, "malloc");
	}
	errcode = check_map_layout(*map);
	deallocate_rows(map_rows);
	if (errcode)
	{
		free_map(map);
		put_map_err_and_exit(errcode);
	}
}

t_map	*create_map(char *map_file)
{
	int			row_count;
	t_map_row	*map_rows;
	t_map		*map;

	map_rows = read_map_rows_from_file(map_file);
	row_count = get_row_count(map_rows);
	if (row_count < 3)
	{
		deallocate_rows(&map_rows);
		put_map_err_and_exit(TOO_NARROW);
	}
	map = init_map();
	if (!map)
	{
		deallocate_rows(&map_rows);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	map->row_count = row_count;
	create_and_check_map_layout(&map, &map_rows);
	return (map);
}
