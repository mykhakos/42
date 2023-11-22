#include "../../include/so_long.h"

/*

void	ft_draw_wall(t_so_long *so_long)
{
	mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->win,
		so_long->textures->wall->img, so_long->x, so_long->y);
}

void	ft_draw_floor(t_so_long *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->so_long, \
		so_long->floor->img_ptr, so_long->x, so_long->y);
}

void	ft_draw_player(int i, t_so_long *so_long)
{
	void	*img_to_draw;

	if (so_long->player->toggle)
	{
		img_to_draw = so_long->player->img_ptr;
	}
	else
	{
		img_to_draw = so_long->player->img2;
	}
	mlx_put_image_to_window(so_long->mlx, so_long->so_long, img_to_draw, \
	so_long->x, so_long->y);
	so_long->player->x = so_long->x;
	so_long->player->y = so_long->y;
	so_long->player->position = i;
	so_long->player->toggle = !so_long->player->toggle;
}

void	ft_draw_collectable(t_so_long *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->so_long, \
		so_long->collectable->img_ptr, so_long->x, so_long->y);
}

void	ft_draw_exit(t_so_long *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->so_long, \
		so_long->escape->img_ptr, so_long->x, so_long->y);
}

*/