/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:22:00 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 15:10:55 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	init_texture_player(t_so_long *so_long)
{
	(*so_long).textures.player_up.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/player_up.xpm",
			&(*so_long).textures.player_up.img_width,
			&(*so_long).textures.player_up.img_height);
	(*so_long).textures.player_down.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/player_down.xpm",
			&(*so_long).textures.player_down.img_width,
			&(*so_long).textures.player_down.img_height);
	(*so_long).textures.player_left.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/player_left.xpm",
			&(*so_long).textures.player_left.img_width,
			&(*so_long).textures.player_left.img_height);
	(*so_long).textures.player_right.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/player_right.xpm",
			&(*so_long).textures.player_right.img_width,
			&(*so_long).textures.player_right.img_height);
}

static void	init_texture_exit(t_so_long *so_long)
{
	(*so_long).textures.exit_closed.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/exit_closed.xpm",
			&(*so_long).textures.exit_closed.img_width,
			&(*so_long).textures.exit_closed.img_height);
	(*so_long).textures.exit_open.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/exit_open.xpm",
			&(*so_long).textures.exit_open.img_width,
			&(*so_long).textures.exit_open.img_height);
}

void	init_textures(t_so_long *so_long)
{
	(*so_long).textures.floor.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/floor.xpm",
			&(*so_long).textures.floor.img_width,
			&(*so_long).textures.floor.img_height);
	(*so_long).textures.wall.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/wall.xpm",
			&(*so_long).textures.wall.img_width,
			&(*so_long).textures.wall.img_height);
	(*so_long).textures.collectible.img_ptr = mlx_xpm_file_to_image(
			(*so_long).mlx.mlx,
			"./textures/collectible.xpm",
			&(*so_long).textures.collectible.img_width,
			&(*so_long).textures.collectible.img_height);
	init_texture_player(so_long);
	init_texture_exit(so_long);
}
