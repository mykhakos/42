#include "../../include/so_long.h"

t_map_pos *init_map_pos(void)
{
    t_map_pos *pos;

    pos = malloc(sizeof(t_map_pos));
    if (!pos)
        perror_with_exit(1, "Memory allocation error.");
    pos->col = 0;
    pos->row = 0;
    return (pos);
}

t_map *init_map_layout(void)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        perror_with_exit(1, "Memory allocation error.");
    map->layout = NULL;
    map->row_count = 0;
    map->col_count = 0;
    map->collectibles_count = 0;
    map->player_pos = init_map_pos();
    map->exit = init_map_pos();
    return (map);
}

void create_map_from_list(t_map *map, t_map_row *rows)
{
    char **layout;
    int row;

    layout = malloc(sizeof(char *) * map->row_count);
    if (!layout)
        perror_with_exit(1, "Memory allocation error.");
    row = 0;
    while (row < map->row_count)
    {
        layout[row] = rows->row;
        row++;
        rows = rows->next;            
    }
    map->layout = layout;
}
