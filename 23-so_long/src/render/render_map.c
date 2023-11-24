/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:30:28 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 18:58:22 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_tile(void *img_ptr, int row, int col, t_so_long *so_long)
{
	mlx_put_image_to_window((*so_long).mlx.mlx, (*so_long).mlx.win, img_ptr,
		col * TILE_SIZE, row * TILE_SIZE);
}

void	render_moves(t_so_long *so_long)
{
	char	*moves;

	mlx_put_image_to_window((*so_long).mlx.mlx, (*so_long).mlx.win,
		(*so_long).textures.wall.img_ptr, TILE_SIZE * 2, TILE_SIZE * 0);
	moves = ft_itoa((*so_long).moves);
	mlx_string_put((*so_long).mlx.mlx, (*so_long).mlx.win, TILE_SIZE / 2,
		TILE_SIZE / 2, 0xFFFFFF, "Moves:");
	mlx_string_put((*so_long).mlx.mlx, (*so_long).mlx.win, TILE_SIZE * 2,
		TILE_SIZE / 2, 0xFFFFFF, moves);
	free(moves);
}

static void	render_map_tile(int row, int col, t_so_long *so_long)
{
	t_textures	textures;
	char		tile_type;

	textures = (*so_long).textures;
	tile_type = so_long->map->layout[row][col];
	if (tile_type == '1')
		render_tile(textures.wall.img_ptr, row, col, so_long);
	else if (tile_type == '0')
		render_tile(textures.floor.img_ptr, row, col, so_long);
	else if (tile_type == 'C')
		render_tile(textures.collectible.img_ptr, row, col, so_long);
	else if (tile_type == 'E')
		render_tile(textures.exit_closed.img_ptr, row, col, so_long);
	else if (tile_type == 'P')
		render_tile(textures.player_right.img_ptr, row, col, so_long);
}

void	render_map_init(t_so_long *so_long)
{
	int	row;
	int	col;

	row = 0;
	while (row < so_long->map->row_count)
	{
		col = 0;
		while (col < so_long->map->col_count)
		{
			render_map_tile(row, col, so_long);
			col++;
		}
		row++;
	}
	render_moves(so_long);
}
