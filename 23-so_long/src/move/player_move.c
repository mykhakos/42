#include "../../include/so_long.h"


static void render_tile(char tile, int tile_row, int tile_col, t_so_long *so_long)
{
	if (tile == '1')
		mlx_put_image_to_window(
			(*so_long).mlx.mlx,
			(*so_long).mlx.win,
			(*so_long).textures.wall.img_ptr,
			tile_col * TILE_SIZE,
			tile_row * TILE_SIZE);
	if (tile == '0')
		mlx_put_image_to_window(
			(*so_long).mlx.mlx,
			(*so_long).mlx.win,
			(*so_long).textures.floor.img_ptr,
			tile_col * TILE_SIZE,
			tile_row * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(
			(*so_long).mlx.mlx,
			(*so_long).mlx.win,
			(*so_long).textures.collectible.img_ptr,
			tile_col * TILE_SIZE,
			tile_row * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(
			(*so_long).mlx.mlx,
			(*so_long).mlx.win,
			(*so_long).textures.exit.img_ptr,
			tile_col * TILE_SIZE,
			tile_row * TILE_SIZE);
}

void render_map(t_so_long *so_long)
{
	int i;
	int j;
	char tile;

	i = 0;
	while (i < so_long->map->row_count)
	{
		j = 0;
		while (j < so_long->map->col_count)
		{
			tile = so_long->map->layout[i][j];
			render_tile(tile, i, j, so_long);
			j++;
		}
		i++;
	}
}

int move(int keycode, t_so_long *so_long)
{
	int old_pos_row;
	int old_pos_col;

	old_pos_row = so_long->map->player_pos->row;
	old_pos_col = so_long->map->player_pos->col;
	if (keycode == XK_w && so_long->map->player_pos->row > 0)
		so_long->map->player_pos->row -= 1;
	else if (keycode == XK_a && so_long->map->player_pos->col > 0)
		so_long->map->player_pos->col -= 1;
	else if (keycode == XK_s)
		so_long->map->player_pos->row += 1;
	else if (keycode == XK_d)
		so_long->map->player_pos->col += 1;
	if (old_pos_row != so_long->map->player_pos->row ||
		old_pos_col != so_long->map->player_pos->col)
		{
		    (*so_long).moves += 1;
            render_map(so_long);
            /*
            mlx_put_image_to_window(
                (*so_long).mlx.mlx,
                (*so_long).mlx.win,
                (*so_long).textures.floor.img_ptr,
                old_pos_col * TILE_SIZE,
                old_pos_row * TILE_SIZE);
            mlx_put_image_to_window(
                (*so_long).mlx.mlx,
                (*so_long).mlx.win,
                (*so_long).textures.floor.img_ptr,
                40,
                10);
            mlx_put_image_to_window(
                (*so_long).mlx.mlx,
                (*so_long).mlx.win,
                (*so_long).textures.player.img_ptr,
                (*so_long).map->player_pos->col * TILE_SIZE,
                (*so_long).map->player_pos->row * TILE_SIZE);
            */
            mlx_string_put((*so_long).mlx.mlx, (*so_long).mlx.win, 10, 20, 0xFFFFFF, "Moves:");
            mlx_string_put((*so_long).mlx.mlx, (*so_long).mlx.win, 50, 20, 0xFFFFFF, ft_itoa((*so_long).moves));
        }
	return (0);
}

