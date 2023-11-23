#include "../include/so_long.h"


t_so_long init_so_long(void)
{
	t_so_long	so_long;

	so_long.moves = 0;
	so_long.collectibles_found = 0;
	so_long.map = NULL;
	so_long.mlx.mlx = NULL;
	so_long.mlx.win = NULL;
	return (so_long);
}

int	main(void)
{
	t_so_long	so_long;

    // if (argc != 2)
    // {
    //     perror("Provide a .ber map file path.\n");
    //     return 0;        
    // }

	so_long = init_so_long();
	so_long.map = create_map("./map.ber");
	so_long.mlx.mlx = mlx_init();
	so_long.mlx.win = mlx_new_window(so_long.mlx.mlx, so_long.map->col_count * TILE_SIZE, so_long.map->row_count * TILE_SIZE, "So Long");
	init_textures(&so_long);
	render_map_init(&so_long);
	mlx_hook(so_long.mlx.win, 2, 1L<<0, hook_keycode, &so_long);
	mlx_hook(so_long.mlx.win, 17, 0, hook_close_window_x, &so_long);
	mlx_loop(so_long.mlx.mlx);
}
