/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:31:08 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 18:31:16 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	*get_player_img_ptr(t_so_long *so_long)
{
	void	*player_img_ptr;

	if (so_long->map->player_dir == N)
		player_img_ptr = (*so_long).textures.player_up.img_ptr;
	else if (so_long->map->player_dir == S)
		player_img_ptr = (*so_long).textures.player_down.img_ptr;
	else if (so_long->map->player_dir == W)
		player_img_ptr = (*so_long).textures.player_left.img_ptr;
	else
		player_img_ptr = (*so_long).textures.player_right.img_ptr;
	return (player_img_ptr);
}

static void	*get_floor_img_ptr(t_so_long *so_long, t_map_pos *tile_pos)
{
	void	*floor_img_ptr;

	if (tile_pos->row == so_long->map->exit->row
		&& tile_pos->col == so_long->map->exit->col)
		floor_img_ptr = (*so_long).textures.exit_closed.img_ptr;
	else
		floor_img_ptr = (*so_long).textures.floor.img_ptr;
	return (floor_img_ptr);
}

void	render_player_move(t_map_pos new_pos, t_so_long *so_long)
{
	mlx_put_image_to_window((*so_long).mlx.mlx, (*so_long).mlx.win,
		get_floor_img_ptr(so_long, so_long->map->player_pos),
		so_long->map->player_pos->col * TILE_SIZE, so_long->map->player_pos->row
		* TILE_SIZE);
	so_long->map->player_pos->row = new_pos.row;
	so_long->map->player_pos->col = new_pos.col;
	mlx_put_image_to_window((*so_long).mlx.mlx, (*so_long).mlx.win,
		get_player_img_ptr(so_long), so_long->map->player_pos->col * TILE_SIZE,
		so_long->map->player_pos->row * TILE_SIZE);
	render_moves(so_long);
}
