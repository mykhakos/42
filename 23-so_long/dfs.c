#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // remove this later

#define ROWS 5
#define COLS 13


typedef struct s_mapPos
{
    int row;
    int col;
}   t_mapPos;


typedef struct s_mapData
{
    char **map;
    int rows;
    int cols;
    int collectibles;
    t_mapPos playerPos;
    t_mapPos exit;
} t_mapData;


typedef struct s_mapRow
{
    char *row;
    int len;
    t_mapRow *next;
} t_mapRow;


/*
int dfs(char **map, int **visited, int row, int col, t_map_data *map_data)
{
    if (row < 0 || row >= map_data->rows || col < 0 || col >= map_data->cols
        || map[row][col] == '1' || visited[row][col])
    {
        return (0);
    }
    visited[row][col] = 1;
    if (map[row][col] == 'C')
        map_data->collectibles -= 1;
    else if (map[row][col] == 'E')
    {
        if (*collectiblesCount == totalCollectibles) {
            return (1);
        }
    }

    // Explore adjacent cells
    if (dfs(map, visited, row + 1, col, map_data) ||
        dfs(map, visited, row - 1, col, map_data) ||
        dfs(map, visited, row, col + 1, map_data) ||
        dfs(map, visited, row, col - 1, map_data)) {
        return (1);
    }

    // Unmark the current cell before backtracking
    visited[row][col] = (0);
    if (map[row][col] == 'C') {
        (*collectiblesCount)--;
    }

    return (0);
}

*/


t_mapRow *create_row(char *row_chars)
{
    t_mapRow *row;

    row = malloc(sizeof(t_mapRow));
    if (!row)
        return (NULL);
    row->row = row_chars;
    row->len = strlen(row_chars);
    return (row);
}


void add_row(t_mapRow **rows, char *new_row_chars)
{
    t_mapRow *new_row;
    t_mapRow *last_row;

    new_row = create_row(new_row_chars);
    last_row = *rows;
    if (last_row == NULL)
    {
        *rows = new_row;
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


int main(int argc, char *argv[])
{
    char **map_data = {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P0011E000001",
        "1111111111111"
        };

    t_mapRow *rows = NULL;
    


}