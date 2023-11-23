#include "../../include/so_long.h"


t_map_row *init_row(char *row_chars)
{
    t_map_row *row;

    row = malloc(sizeof(t_map_row));
    if (!row)
        return (NULL);
    row->row = row_chars;
    row->next = NULL;
    return (row);
}

void append_row(t_map_row **rows, char *new_row_chars)
{
    t_map_row *new_row;
    t_map_row *last_row;

    new_row = init_row(new_row_chars);
    last_row = *rows;
    if (last_row == NULL)
    {
        *rows = new_row;
    }
    else
    {
        while (last_row->next != NULL)
            last_row = last_row->next;
        last_row->next = new_row;
    }
}

void deallocate_rows(t_map_row **rows)
{
    t_map_row *current;
    t_map_row *next;

    current = *rows;
    while (current != NULL)
    {
        next = current->next;
        free(current->row);
        free(current);
        current = next;
    }
    *rows = NULL;
}
