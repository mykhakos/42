#include "../map.h"

t_mapPos *init_map_pos(void)
{
    t_mapPos *pos;

    pos = malloc(sizeof(t_mapPos));
    if (!pos)
        perror_with_exit(1, "Memory allocation error.");
    pos->col = 0;
    pos->row = 0;
    return (pos);
}

t_mapLayout *init_map_layout(void)
{
    t_mapLayout *layout;

    layout = malloc(sizeof(t_mapLayout));
    if (!layout)
        perror_with_exit(1, "Memory allocation error.");
    layout->map = NULL;
    layout->row_count = 0;
    layout->col_count = 0;
    layout->collectibles_count = 0;
    layout->player_pos = init_map_pos();
    layout->exit = init_map_pos();
    return (layout);
}

void create_map_from_list(t_mapLayout *layout, t_mapRow *rows)
{
    char **map;
    int row;

    map = malloc(sizeof(char *) * layout->row_count);
    if (!map)
        perror_with_exit(1, "Memory allocation error.");
    row = 0;
    while (row < layout->row_count)
    {
        map[row] = rows->row;
        row++;
        rows = rows->next;            
    }
    layout->map = map;
}
