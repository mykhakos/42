#include "../../include/so_long.h"

static void free_visited_map(int ***map, int row_count)
{
    int i;

    i = 0;
    while (i < row_count)
    {
        free((*map)[i]);
        i++;
    }
    free(*map);
}

static int **create_visited_map(t_map *map)
{
    int **visited_map;
    int row;
    int col;

    visited_map = malloc(sizeof(int *) * map->row_count);
    if (!visited_map)
        perror_with_exit(1, "Memory allocation error.");
    row = 0;
    while (row < map->row_count)
    {
        visited_map[row] = malloc(sizeof(int) * map->col_count);
        if (!visited_map[row])
            free_visited_map(&visited_map, row);
        col = 0;
        while (col < map->col_count)
        {
            visited_map[row][col] = 0;
            col++;
        }
        row++;
    }
    return (visited_map);
}

static t_dfs_data init_dfs_data(t_map *map)
{
    t_dfs_data dfs_data;

    dfs_data.visited = create_visited_map(map);
    dfs_data.collectibles_found = 0;
    dfs_data.exit_found = 0;
    return (dfs_data);
}

static void dfs(int row, int col, char **map_layout, t_dfs_data *dfs_data)
{
    char cell;

    cell = map_layout[row][col];
    if (cell == '1' || dfs_data->visited[row][col])
        return ;
    else if (cell == 'E')
        dfs_data->exit_found = 1;
    else if (cell == 'C')
        dfs_data->collectibles_found += 1;
    dfs_data->visited[row][col] = 1;
    dfs(row - 1, col, map_layout, dfs_data);
    dfs(row, col - 1, map_layout, dfs_data);
    dfs(row + 1, col, map_layout, dfs_data);
    dfs(row, col + 1, map_layout, dfs_data);
}

void check_map_layout(t_map *map)
{
    t_dfs_data dfs_data;

    dfs_data = init_dfs_data(map);
    dfs(map->player_pos->row, map->player_pos->col, map->layout, &dfs_data);
    free_visited_map(&dfs_data.visited, map->row_count);
    if (!dfs_data.exit_found)
    {
        perror_with_exit(1, "Map does not have an exit path.");
    }
    if (dfs_data.collectibles_found != (*map).collectibles_count)
    {
        perror_with_exit(1, "Not all collectibles on the map are reachable.");
    }
}
