#include "../include/so_long.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 800, 400, "Hello world!");
// 	mlx_loop(mlx);
// }

#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100


int	close_window(int keycode, t_mlx *vars)
{
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("keycode: %i\n", keycode);
	return (0);
}




t_map *get_map(char *map_file)
{
	int map_fd;
    char *row_chars;
    t_map_row *map_rows;
    t_map *map_layout;

    map_fd = open(map_file, O_RDONLY);
    if (map_fd == -1)
    {
        perror("Error occured while opening the map file.");
        return (NULL);
    }
    row_chars = get_next_line(map_fd);
    if (!row_chars)
        perror_with_exit(1, ".ber map file is empty.");
    map_rows = NULL;
    while (row_chars != NULL)
    {
        append_row(&map_rows, ft_strtrim(row_chars, "\n"));
        row_chars = get_next_line(map_fd);
    }
    map_layout = check_map_rows(map_rows);
    create_map_from_list(map_layout, map_rows);

    check_map_layout(map_layout);

    close(map_fd);

	return (map_layout);
}


void init_tetxures(t_so_long *so_long)
{
	(*so_long).textures.floor.img_ptr = mlx_xpm_file_to_image(
		(*so_long).mlx.mlx,
		"./textures/black.xpm",
		&(*so_long).textures.floor.img_width,
		&(*so_long).textures.floor.img_height);
	(*so_long).textures.wall.img_ptr = mlx_xpm_file_to_image(
		(*so_long).mlx.mlx,
		"./textures/wall.xpm",
		&(*so_long).textures.wall.img_width,
		&(*so_long).textures.wall.img_height);
	(*so_long).textures.player.img_ptr = mlx_xpm_file_to_image(
		(*so_long).mlx.mlx,
		"./textures/player.xpm",
		&(*so_long).textures.player.img_width,
		&(*so_long).textures.player.img_height);
	(*so_long).textures.exit.img_ptr = mlx_xpm_file_to_image(
		(*so_long).mlx.mlx,
		"./textures/exit.xpm",
		&(*so_long).textures.exit.img_width,
		&(*so_long).textures.exit.img_height);
	(*so_long).textures.collectible.img_ptr = mlx_xpm_file_to_image(
		(*so_long).mlx.mlx,
		"./textures/collectible.xpm",
		&(*so_long).textures.collectible.img_width,
		&(*so_long).textures.collectible.img_height);
}

int	main(void)
{
	t_so_long	so_long;

	so_long.map = get_map("./map.ber");
	so_long.mlx.mlx = mlx_init();
	so_long.mlx.win = mlx_new_window(so_long.mlx.mlx, 800, 600, "So Long");
	init_tetxures(&so_long);
	render_map(&so_long);
	mlx_hook(so_long.mlx.win, 2, 1L<<0, close_window, &so_long);
	mlx_hook(so_long.mlx.win, 4, 1L<<2, close_window, &so_long);
	so_long.moves = 0;

	mlx_put_image_to_window(
		so_long.mlx.mlx,
		so_long.mlx.win,
		so_long.textures.player.img_ptr,
		so_long.map->player_pos->col * TILE_SIZE,
		so_long.map->player_pos->row * TILE_SIZE);
	mlx_hook(so_long.mlx.win, 2, 1L<<0, move, &so_long);
	mlx_string_put(so_long.mlx.mlx, so_long.mlx.win, 10, 20, 0xFFFFFF, "Moves:");
	mlx_string_put(so_long.mlx.mlx, so_long.mlx.win, 50, 20, 0xFFFFFF, "0");
	mlx_loop(so_long.mlx.mlx);
}

// https://github.com/xhelp00/so_long/tree/master/src