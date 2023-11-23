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

t_map *init_map(void)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        perror_with_exit(1, "Memory allocation error.");
    map->layout = NULL;
    map->row_count = 0;
    map->col_count = 0;
    map->collectibles_count = 0;
    map->player_dir = E;
    map->player_pos = init_map_pos();
    map->exit = init_map_pos();
    return (map);
}

static char **create_map_layout(t_map_row *rows, int row_count)
{
    char **layout;
    int row;

    layout = malloc(sizeof(char *) * row_count);
    if (!layout)
        perror_with_exit(1, "Memory allocation error.");
    row = 0;
    while (row < row_count)
    {
        layout[row] = ft_strdup(rows->row);
        row++;
        rows = rows->next;            
    }
    return (layout);
}

t_map *create_map(char *map_file)
{
	int map_fd;
    char *row_chars;
    t_map_row *map_rows;
    t_map *map;

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
        free(row_chars);
        row_chars = get_next_line(map_fd);
    }
    map = check_map_chars(map_rows);
    map->layout = create_map_layout(map_rows, map->row_count);
	deallocate_rows(&map_rows);
    check_map_layout(map);
    close(map_fd);
	return (map);
}