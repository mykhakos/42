/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:13:32 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 18:17:08 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	safe_destroy_image(t_texture texture, void *mlx_ptr)
{
	if (texture.img_ptr)
		mlx_destroy_image(mlx_ptr, texture.img_ptr);
}

void	free_map(t_map **map_ptr)
{
	int		i;
	t_map	*map;

	if (!map_ptr)
		return ;
	map = *map_ptr;
	if (map->layout)
	{
		i = 0;
		while (i < map->row_count)
		{
			free(map->layout[i]);
			i++;
		}
		free(map->layout);
	}
	if (map->exit)
		free(map->exit);
	if (map->player_pos)
		free(map->player_pos);
	free(map);
}

void	exit_game(t_so_long *so_long)
{
	safe_destroy_image(so_long->textures.collectible, so_long->mlx.mlx);
	safe_destroy_image(so_long->textures.exit_closed, so_long->mlx.mlx);
	safe_destroy_image(so_long->textures.exit_open, so_long->mlx.mlx);
	safe_destroy_image(so_long->textures.floor, so_long->mlx.mlx);
	safe_destroy_image(so_long->textures.player_up, so_long->mlx.mlx);
	safe_destroy_image(so_long->textures.player_down, so_long->mlx.mlx);
	safe_destroy_image(so_long->textures.player_left, so_long->mlx.mlx);
	safe_destroy_image(so_long->textures.player_right, so_long->mlx.mlx);
	safe_destroy_image(so_long->textures.wall, so_long->mlx.mlx);
	free_map(&(so_long->map));
	mlx_destroy_window(so_long->mlx.mlx, so_long->mlx.win);
	mlx_destroy_display(so_long->mlx.mlx);
	free(so_long->mlx.mlx);
	exit(0);
}

int	hook_close_window_esc(int keycode, t_so_long *so_long)
{
	if (keycode == XK_Escape)
		exit_game(so_long);
	return (0);
}

int	hook_close_window_x(t_so_long *so_long)
{
	exit_game(so_long);
	return (0);
}
