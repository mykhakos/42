#include "../../include/so_long.h"


static void	safe_destroy_image(t_texture texture, void *mlx_ptr)
{
	if (texture.img_ptr)
	    mlx_destroy_image(mlx_ptr, texture.img_ptr);
}

static void free_map(t_map **map_ptr)
{
    int i;
    t_map *map;

    map = *map_ptr;
    i = 0;
    while (i < map->row_count)
    {
        free(map->layout[i]);
        i++;
    }
    free(map->layout);
    free(map->exit);
    free(map->player_pos);
    free(map);
}

int exit_game(t_so_long *so_long)
{
    safe_destroy_image(so_long->textures.collectible, so_long->mlx.mlx);
    safe_destroy_image(so_long->textures.exit_closed, so_long->mlx.mlx);
    safe_destroy_image(so_long->textures.exit_open, so_long->mlx.mlx);
    safe_destroy_image(so_long->textures.floor, so_long->mlx.mlx);
    safe_destroy_image(so_long->textures.player, so_long->mlx.mlx);
    safe_destroy_image(so_long->textures.wall, so_long->mlx.mlx);
    free_map(&(so_long->map));
	mlx_destroy_window(so_long->mlx.mlx, so_long->mlx.win);
	mlx_destroy_display(so_long->mlx.mlx);
    free(so_long->mlx.mlx);
    exit(0);
}