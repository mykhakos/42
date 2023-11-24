/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:03:49 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 20:47:29 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_map_errcode	check_first_last_row_chars(char *row_chars,
		int *row_len)
{
	int	len;

	len = 0;
	while (row_chars[len] != '\0')
	{
		if (row_chars[len] != '1')
			return (BORDER_NOT_CONTINUOUS);
		len++;
	}
	if (len < 3)
		return (TOO_NARROW);
	*row_len = len;
	return (NONE);
}

static t_map_errcode	check_char(char c, int row, int col, t_map *map)
{
	t_map_errcode	errcode;

	if (c == 'C')
		map->collectibles_count += 1;
	else if (c == 'P')
	{
		errcode = update_pos_if_zero(row, col, map->player_pos);
		if (errcode)
			return (errcode);
	}
	else if (c == 'E')
	{
		errcode = update_pos_if_zero(row, col, map->exit);
		if (errcode)
			return (errcode);
	}
	else if (c != '0' && c != '1')
		return (CHAR_INVALID);
	return (NONE);
}

static t_map_errcode	check_middle_row_chars(char *row_chars, int row,
		t_map *map)
{
	int				col;
	t_map_errcode	errcode;

	col = 0;
	while (row_chars[col] != '\0')
	{
		errcode = check_char(row_chars[col], row, col, map);
		if (errcode)
			return (errcode);
		col++;
	}
	if (col != map->col_count)
		return (WIDTH_INCONSISTENT);
	if (row_chars[0] != '1' || row_chars[col - 1] != '1')
		return (BORDER_NOT_CONTINUOUS);
	return (NONE);
}

static t_map_errcode	check_map_important_chars(t_map *map)
{
	if (map->player_pos->row == 0 || map->player_pos->col == 0)
		return (INVALID_CHAR_COUNT_PLAYER);
	if (map->exit->row == 0 || map->exit->col == 0)
		return (INVALID_CHAR_COUNT_EXIT);
	if (map->collectibles_count == 0)
		return (INVALID_CHAR_COUNT_COLLECTIBLE);
	return (NONE);
}

t_map_errcode	check_map_chars(t_map *map, t_map_row *map_rows)
{
	t_map_errcode	errcode;
	int				row;

	errcode = check_first_last_row_chars(map_rows->row, &(map->col_count));
	if (errcode)
		return (errcode);
	map_rows = map_rows->next;
	row = 1;
	while (map_rows->next != NULL)
	{
		errcode = check_middle_row_chars(map_rows->row, row, map);
		if (errcode)
			return (errcode);
		row++;
		map_rows = map_rows->next;
	}
	errcode = check_first_last_row_chars(map_rows->row, &(map->col_count));
	if (errcode)
		return (errcode);
	errcode = check_map_important_chars(map);
	if (errcode)
		return (errcode);
	return (NONE);
}
