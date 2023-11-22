#include "../../include/so_long.h"


static int check_first_and_last_row(char *row_chars)
{
    int row_len;

    row_len = 0;
    while (row_chars[row_len] != '\0')
    {
        if (row_chars[row_len] != '1')
            perror_with_exit(1, "Map border is not continuous.");            
        row_len++;
    }
    if (row_len < 3)
        perror_with_exit(1, "Map is too narrow.");
    return (row_len);
}

static void ensure_pos_is_unique(int row, int col, t_map_pos *pos)
{
    if (pos->row != 0 || pos->col != 0)
        perror_with_exit(1, "Map contains multiple unique characters.");
    pos->row = row;
    pos->col = col;
}

static void chech_row_char(char c, int row, int col, t_map *map)
{
    if (c == 'C')
        map->collectibles_count += 1;
    else if (c == 'P')
        ensure_pos_is_unique(row, col, map->player_pos);
    else if (c == 'E')
        ensure_pos_is_unique(row, col, map->exit);
    else if (c != '0' && c != '1')
        perror_with_exit(1, "Map characters are invalid.");
}

static void check_row(char *row_chars, int row, t_map *map)
{
    int col;

    col = 0;
    while (row_chars[col] != '\0')
    {
        chech_row_char(row_chars[col], row, col, map);
        col++;
    }
    if (col != map->col_count)
        perror_with_exit(1, "Map width is not consistent.");
    if (row_chars[0] != '1' || row_chars[col - 1] != '1')
        perror_with_exit(1, "Map border is not continuous.");
}

t_map *check_map_rows(t_map_row *map_rows)
{
    t_map *map;

    if (!map_rows)
        perror_with_exit(1, "t_map_rowsRow pointer points to NULL.");
    map = init_map_layout();
    map->col_count = check_first_and_last_row(map_rows->row);
    map->row_count += 1;
    map_rows = map_rows->next;
    while (map_rows->next != NULL)
    {
        check_row(map_rows->row, map->row_count, map);
        map_rows = map_rows->next;
        map->row_count += 1;
    }
    if (check_first_and_last_row(map_rows->row) != map->col_count)
        perror_with_exit(1, "Map width is not consistent.");
    map->row_count += 1;
    if (map->player_pos->row == 0 || map->player_pos->col == 0)
        perror_with_exit(1, "Map requires one player position character.");
    if (map->exit->row == 0 || map->exit->col == 0)
        perror_with_exit(1, "Map requires one exit character.");
    if (map->collectibles_count == 0)
        perror_with_exit(1, "Map requires at least one collectible.");
    return (map);
}
