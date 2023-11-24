/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:13:56 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 18:37:36 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_map_pos	calc_new_pos(int keycode, t_so_long *so_long)
{
	t_map_pos	new_pos;

	new_pos.row = so_long->map->player_pos->row;
	new_pos.col = so_long->map->player_pos->col;
	if (keycode == XK_w)
	{
		new_pos.row -= 1;
		so_long->map->player_dir = N;
	}
	else if (keycode == XK_a)
	{
		new_pos.col -= 1;
		so_long->map->player_dir = W;
	}
	else if (keycode == XK_s)
	{
		new_pos.row += 1;
		so_long->map->player_dir = S;
	}
	else if (keycode == XK_d)
	{
		new_pos.col += 1;
		so_long->map->player_dir = E;
	}
	return (new_pos);
}

static int	update_player_pos(t_map_pos curr_pos, t_map_pos new_pos,
		t_so_long *so_long)
{
	int		collectibles_found;

	if (so_long->map->layout[new_pos.row][new_pos.col] == '1')
	{
		render_player_move(curr_pos, so_long);
		return (0);
	}
	if (so_long->map->layout[new_pos.row][new_pos.col] == 'E')
	{
		collectibles_found = (*so_long).collectibles_found;
		if (collectibles_found >= so_long->map->collectibles_count)
			exit_game(so_long);
	}
	if (so_long->map->layout[new_pos.row][new_pos.col] == 'C')
	{
		(*so_long).collectibles_found += 1;
		collectibles_found = (*so_long).collectibles_found;
		if (collectibles_found >= so_long->map->collectibles_count)
			render_tile(so_long->textures.exit_open.img_ptr,
				so_long->map->exit->row, so_long->map->exit->col, so_long);
	}
	(so_long)->moves += 1;
	render_player_move(new_pos, so_long);
	return (1);
}

int	hook_player_move(int keycode, t_so_long *so_long)
{
	t_map_pos	new_pos;
	t_map_pos	curr_pos;

	curr_pos.col = so_long->map->player_pos->col;
	curr_pos.row = so_long->map->player_pos->row;
	new_pos = calc_new_pos(keycode, so_long);
	if (new_pos.row != curr_pos.row || new_pos.col != curr_pos.col)
	{
		if (update_player_pos(curr_pos, new_pos, so_long))
			ft_printf("Moves: %i\n", (*so_long).moves);
	}
	return (0);
}
