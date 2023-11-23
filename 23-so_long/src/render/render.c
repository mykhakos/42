#include "../../include/so_long.h"

void	render_tile(void *img_ptr, int row, int col, t_so_long *so_long)
{
	mlx_put_image_to_window((*so_long).mlx.mlx, (*so_long).mlx.win, img_ptr,
		col * TILE_SIZE, row * TILE_SIZE);
}

static void render_moves(t_so_long *so_long)
{
	char *moves;

	ft_printf("Moves: %i\n", (*so_long).moves);
	mlx_put_image_to_window((*so_long).mlx.mlx, (*so_long).mlx.win,
		(*so_long).textures.wall.img_ptr, TILE_SIZE * 2, TILE_SIZE * 0);
	moves = ft_itoa((*so_long).moves);
	mlx_string_put((*so_long).mlx.mlx, (*so_long).mlx.win, TILE_SIZE / 2,
		TILE_SIZE / 2, 0xFFFFFF, "Moves:");
	mlx_string_put((*so_long).mlx.mlx, (*so_long).mlx.win, TILE_SIZE * 2,
		TILE_SIZE / 2, 0xFFFFFF, moves);
	free(moves);
}

void	render_map_init(t_so_long *so_long)
{
	int		i;
	int		j;
	t_textures textures;

    textures = (*so_long).textures;
	i = 0;
	while (i < so_long->map->row_count)
	{
		j = 0;
		while (j < so_long->map->col_count)
		{
			if (so_long->map->layout[i][j] == '1')
				render_tile(textures.wall.img_ptr, i, j, so_long);
			else if (so_long->map->layout[i][j] == '0')
				render_tile(textures.floor.img_ptr, i, j, so_long);
			else if (so_long->map->layout[i][j] == 'C')
				render_tile(textures.collectible.img_ptr, i, j, so_long);
			else if (so_long->map->layout[i][j] == 'E')
				render_tile(textures.exit_closed.img_ptr, i, j, so_long);
			else if (so_long->map->layout[i][j] == 'P')
				render_tile(textures.player.img_ptr, i, j, so_long);
			j++;
		}
		i++;
	}
	render_moves(so_long);
}

void	render_player_move(t_map_pos new_pos, t_so_long *so_long)
{
	mlx_put_image_to_window((*so_long).mlx.mlx, (*so_long).mlx.win,
		(*so_long).textures.floor.img_ptr, so_long->map->player_pos->col
		* TILE_SIZE, so_long->map->player_pos->row * TILE_SIZE);
	so_long->map->player_pos->row = new_pos.row;
	so_long->map->player_pos->col = new_pos.col;
	mlx_put_image_to_window((*so_long).mlx.mlx, (*so_long).mlx.win,
		(*so_long).textures.player.img_ptr, so_long->map->player_pos->col
		* TILE_SIZE, so_long->map->player_pos->row * TILE_SIZE);
	(*so_long).moves += 1;
	render_moves(so_long);
}
