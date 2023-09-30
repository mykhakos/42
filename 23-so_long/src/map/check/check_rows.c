#include "../map.h"

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

static void ensure_pos_is_unique(int row, int col, t_mapPos *pos)
{
    if (pos->row != 0 || pos->col != 0)
        perror_with_exit(1, "Map contains multiple unique characters.");
    pos->row = row;
    pos->col = col;
}

static void chech_row_char(char c, int row, int col, t_mapLayout *layout)
{
    if (c == 'C')
        layout->collectibles_count += 1;
    else if (c == 'P')
        ensure_pos_is_unique(row, col, layout->player_pos);
    else if (c == 'E')
        ensure_pos_is_unique(row, col, layout->exit);
    else if (c != '0' && c != '1')
        perror_with_exit(1, "Map characters are invalid.");
}

static void check_row(char *row_chars, int row, t_mapLayout *layout)
{
    int col;

    col = 0;
    while (row_chars[col] != '\0')
    {
        chech_row_char(row_chars[col], row, col, layout);
        col++;
    }
    if (col != layout->col_count)
        perror_with_exit(1, "Map width is not consistent.");
    if (row_chars[0] != '1' || row_chars[col - 1] != '1')
        perror_with_exit(1, "Map border is not continuous.");
}

t_mapLayout *check_map_rows(t_mapRow *map_rows)
{
    t_mapLayout *layout;

    if (!map_rows)
        perror_with_exit(1, "t_map_rowsRow pointer points to NULL.");
    layout = init_map_layout();
    layout->col_count = check_first_and_last_row(map_rows->row);
    layout->row_count += 1;
    map_rows = map_rows->next;
    while (map_rows->next != NULL)
    {
        check_row(map_rows->row, layout->row_count, layout);
        map_rows = map_rows->next;
        layout->row_count += 1;
    }
    if (check_first_and_last_row(map_rows->row) != layout->col_count)
        perror_with_exit(1, "Map width is not consistent.");
    layout->row_count += 1;
    if (layout->player_pos->row == 0 || layout->player_pos->col == 0)
        perror_with_exit(1, "Map requires one player position character.");
    if (layout->exit->row == 0 || layout->exit->col == 0)
        perror_with_exit(1, "Map requires one exit character.");
    if (layout->collectibles_count == 0)
        perror_with_exit(1, "Map requires at least one collectible.");
    return (layout);
}
