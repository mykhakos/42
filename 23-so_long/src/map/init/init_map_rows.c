#include "../map.h"

t_mapRow *init_row(char *row_chars)
{
    t_mapRow *row;

    row = malloc(sizeof(t_mapRow));
    if (!row)
        return (NULL);
    row->row = row_chars;
    return (row);
}

void append_row(t_mapRow **map, char *new_row_chars)
{
    t_mapRow *new_row;
    t_mapRow *last_row;

    new_row = init_row(new_row_chars);
    last_row = *map;
    if (last_row == NULL)
    {
        *map = new_row;
    }
    else
    {
        while (last_row->next != NULL)
        {
            last_row = last_row->next;
        }
        last_row->next = new_row;
    }
}


void deallocate_rows(t_mapRow **rows)
{
    while ((*rows) != NULL)
    {
        free(*rows);
    }
    free(rows);
}
