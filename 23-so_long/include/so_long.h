#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"

# include <stdlib.h> 
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysym.h>

# define TILE_SIZE 32

typedef struct s_map_traversal
{
    int exit_found;
    int collectibles_found;
} t_map_traversal;

typedef struct s_dfs_data
{
    int **visited;
    int exit_found;
    int collectibles_found;
} t_dfs_data;

typedef struct s_map_row
{
    char *row;
    struct s_map_row *next;
} t_map_row;

typedef struct s_map_pos
{
    int row;
    int col;
} t_map_pos;

typedef enum s_player_direction
{
    N,
    S,
    E,
    W
} t_player_direction;

typedef struct s_map
{
    char **layout;
    int row_count;
    int col_count;
    int collectibles_count;
    t_player_direction player_dir;
    t_map_pos *player_pos;
    t_map_pos *exit;
} t_map;

typedef struct	s_texture
{
	void	*img_ptr;
    int     img_height;
    int     img_width;
}   t_texture;

typedef struct	s_textures
{
	t_texture	wall;
	t_texture	floor;
	t_texture	player;
    t_texture	collectible;
    t_texture	exit_closed;
    t_texture	exit_open;
}   t_textures;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}   t_mlx;

typedef struct s_so_long
{
    t_mlx mlx;
    t_map *map;
    t_textures textures;
    int moves;
    int collectibles_found;
}   t_so_long;

t_map_row *init_row(char *row_chars);
void append_row(t_map_row **map, char *new_row_chars);
void deallocate_rows(t_map_row **map);
t_map *check_map_chars(t_map_row *map);
void check_map_layout(t_map *map_layout);
t_map *init_map(void);

void perror_with_exit(int exit_code, char *err_msg);

void render_map_init(t_so_long *so_long);
void render_player_move(t_map_pos new_pos, t_so_long *so_long);
int exit_game(t_so_long *so_long);
t_map *create_map(char *map_file);
int	hook_close_window_x(t_so_long *so_long);
int hook_keycode(int keycode, t_so_long *so_long);
void	render_tile(void *img_ptr, int row, int col, t_so_long *so_long);
void init_textures(t_so_long *so_long);


#endif