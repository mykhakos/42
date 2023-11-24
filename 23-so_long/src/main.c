/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:34:01 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 20:53:14 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_so_long	init_so_long(void)
{
	t_so_long	so_long;

	so_long.moves = 0;
	so_long.collectibles_found = 0;
	so_long.map = NULL;
	so_long.mlx.mlx = NULL;
	so_long.mlx.win = NULL;
	return (so_long);
}

static int	hook_keycode(int keycode, t_so_long *so_long)
{
	hook_close_window_esc(keycode, so_long);
	hook_player_move(keycode, so_long);
	return (0);
}

int	main(int argc, char **argv)
{
	t_so_long	so_long;

	if (argc != 2)
	{
		ft_printf("Invalid number of args (expected two).\n");
		return (EXIT_FAILURE);
	}
	so_long = init_so_long();
	so_long.map = create_map(argv[1]);
	so_long.mlx.mlx = mlx_init();
	so_long.mlx.win = mlx_new_window(
			so_long.mlx.mlx,
			so_long.map->col_count * TILE_SIZE,
			so_long.map->row_count * TILE_SIZE,
			"So Long");
	init_textures(&so_long);
	render_map_init(&so_long);
	mlx_hook(so_long.mlx.win, 2, 1L << 0, hook_keycode, &so_long);
	mlx_hook(so_long.mlx.win, 17, 0, hook_close_window_x, &so_long);
	mlx_loop(so_long.mlx.mlx);
}
