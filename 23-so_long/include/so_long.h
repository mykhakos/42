#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> 
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysym.h>

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"

# define TILE_SIZE 32

typedef struct s_map_traversal
{
    int exit_found;
    int collectibles_found;
} t_map_traversal;

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


typedef struct s_map
{
    char **layout;
    int row_count;
    int col_count;
    int collectibles_count;
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
    t_texture	exit;
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
    int collectibles_total;
}   t_so_long;

t_map_row *init_row(char *row_chars);
void append_row(t_map_row **map, char *new_row_chars);
void deallocate_rows(t_map_row **map);
t_map *check_map_rows(t_map_row *map);
void check_map_layout(t_map *map_layout);
void create_map_from_list(t_map *layout, t_map_row *rows);
t_map *init_map_layout(void);

void perror_with_exit(int exit_code, char *err_msg);

int move(int keycode, t_so_long *so_long);
void render_map(t_so_long *so_long);

#endif