/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <kmykhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:10:23 by kmykhail          #+#    #+#             */
/*   Updated: 2023/11/24 20:50:58 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_map_traversal
{
	int					exit_found;
	int					collectibles_found;
}						t_map_traversal;

typedef struct s_dfs_data
{
	int					**visited;
	int					exit_found;
	int					collectibles_found;
}						t_dfs_data;

typedef struct s_map_row
{
	char				*row;
	struct s_map_row	*next;
}						t_map_row;

typedef struct s_map_pos
{
	int					row;
	int					col;
}						t_map_pos;

typedef enum s_player_direction
{
	N,
	S,
	E,
	W
}						t_player_direction;

typedef struct s_map
{
	char				**layout;
	int					row_count;
	int					col_count;
	int					collectibles_count;
	t_player_direction	player_dir;
	t_map_pos			*player_pos;
	t_map_pos			*exit;
}						t_map;

typedef enum s_map_errcode
{
	NONE,
	MALLOC_FAIL,
	BORDER_NOT_CONTINUOUS,
	TOO_NARROW,
	MULTIPLE_UNIQUE_CHARS,
	CHAR_INVALID,
	WIDTH_INCONSISTENT,
	INVALID_CHAR_COUNT_PLAYER,
	INVALID_CHAR_COUNT_EXIT,
	INVALID_CHAR_COUNT_COLLECTIBLE,
	NO_EXIT_PATH,
	NOT_ALL_COLLECTIBLES_REACHABLE
}						t_map_errcode;

typedef struct s_texture
{
	void				*img_ptr;
	int					img_height;
	int					img_width;
}						t_texture;

typedef struct s_textures
{
	t_texture			wall;
	t_texture			floor;
	t_texture			player_up;
	t_texture			player_down;
	t_texture			player_left;
	t_texture			player_right;
	t_texture			collectible;
	t_texture			exit_closed;
	t_texture			exit_open;
}						t_textures;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
}						t_mlx;

typedef struct s_so_long
{
	t_mlx				mlx;
	t_map				*map;
	t_textures			textures;
	int					moves;
	int					collectibles_found;
}						t_so_long;

t_map_row				*init_row(char *row_chars);
void					append_row(t_map_row **rows, char *new_row_chars);
void					deallocate_rows(t_map_row **rows);
t_map_row				*read_map_rows_from_file(char *map_file);
int						get_row_count(t_map_row *rows);

t_map					*init_map(void);
t_map					*create_map(char *map_file);
void					init_textures(t_so_long *so_long);
t_map_errcode			update_pos_if_zero(int row, int col, t_map_pos *pos);
t_map_errcode			check_map_chars(t_map *map, t_map_row *map_rows);
t_map_errcode			check_map_layout(t_map *map);
void					free_map(t_map **map_ptr);

void					render_tile(void *img_ptr, int row, int col,
							t_so_long *so_long);
void					render_map_init(t_so_long *so_long);
void					render_moves(t_so_long *so_long);
void					render_player_move(t_map_pos new_pos,
							t_so_long *so_long);

int						hook_player_move(int keycode, t_so_long *so_long);
int						hook_close_window_esc(int keycode, t_so_long *so_long);
int						hook_close_window_x(t_so_long *so_long);

void					exit_game(t_so_long *so_long);

char					*get_map_err_msg(t_map_errcode errcode);
void					put_map_err_and_exit(t_map_errcode errcode);
void					perror_and_exit(int exit_code, char *err_msg);

#endif