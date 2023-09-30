#ifndef MAP_H
# define MAP_H

#include <stdlib.h> 
#include "../utils/utils.h"
#include "../../libft/libft.h"

typedef struct s_mapRow
{
    char *row;
    struct s_mapRow *next;
} t_mapRow;

typedef struct s_mapPos
{
    int row;
    int col;
} t_mapPos;

typedef struct s_mapLayout
{
    char **map;
    int row_count;
    int col_count;
    int collectibles_count;
    struct s_mapPos *player_pos;
    struct s_mapPos *exit;
} t_mapLayout;

typedef struct s_mapTraversal
{
    int exit_found;
    int collectibles_found;
} t_mapTraversal;

t_mapRow *init_row(char *row_chars);
void append_row(t_mapRow **map, char *new_row_chars);
void deallocate_rows(t_mapRow **map);
t_mapLayout *check_map_rows(t_mapRow *map);
void check_map_layout(t_mapLayout *map_layout);
void create_map_from_list(t_mapLayout *layout, t_mapRow *rows);
t_mapLayout *init_map_layout(void);

#endif