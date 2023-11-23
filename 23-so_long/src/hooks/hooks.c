#include "../../include/so_long.h"

static t_map_pos	calc_new_pos(int keycode, t_so_long *so_long)
{
	t_map_pos	new_pos;

	new_pos.row = so_long->map->player_pos->row;
	new_pos.col = so_long->map->player_pos->col;
	if (keycode == XK_w)
	{
		new_pos.row -= 1;
		so_long->map->player_dir = N;
	}
	else if (keycode == XK_a)
	{
		new_pos.col -= 1;
		so_long->map->player_dir = W;
	}
	else if (keycode == XK_s)
	{
		new_pos.row += 1;
		so_long->map->player_dir = S;
	}
	else if (keycode == XK_d)
	{
		new_pos.col += 1;
		so_long->map->player_dir = E;
	}
	return (new_pos);
}


static int	handle_player_move(int keycode, t_so_long *so_long)
{
	t_map_pos	new_pos;
	t_map_pos	curr_pos;
	char		new_tile;
	int			collectibles_found;

	curr_pos.col = so_long->map->player_pos->col;
	curr_pos.row = so_long->map->player_pos->row;
	new_pos = calc_new_pos(keycode, so_long);
	if (new_pos.row != curr_pos.row || new_pos.col != curr_pos.col)
	{
		new_tile = so_long->map->layout[new_pos.row][new_pos.col];
		if (new_tile == '1')
		{
			render_player_move(curr_pos, so_long);
			return (0);
		}
		if (new_tile == 'E')
		{
			collectibles_found = (*so_long).collectibles_found;
			if (collectibles_found < so_long->map->collectibles_count)
			{
				render_player_move(curr_pos, so_long);
				return (0);
			}
			exit_game(so_long);
		}
		if (new_tile == 'C')
		{
			(*so_long).collectibles_found += 1;
			collectibles_found = (*so_long).collectibles_found;
			if (collectibles_found >= so_long->map->collectibles_count)
				render_tile(so_long->textures.exit_open.img_ptr,
					so_long->map->exit->row, so_long->map->exit->col, so_long);
		}
		(so_long)->moves += 1;
		ft_printf("Moves: %i\n", (*so_long).moves);
		render_player_move(new_pos, so_long);
	}
	return (0);
}

static int	handle_close_window_esc(int keycode, t_so_long *so_long)
{
	if (keycode == XK_Escape)
		exit_game(so_long);
	return (0);
}

int	hook_keycode(int keycode, t_so_long *so_long)
{
	handle_close_window_esc(keycode, so_long);
	handle_player_move(keycode, so_long);
	return (0);
}

int	hook_close_window_x(t_so_long *so_long)
{
	exit_game(so_long);
	return (0);
}
