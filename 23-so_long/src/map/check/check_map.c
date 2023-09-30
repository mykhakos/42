#include "../map.h"


static int **create_visited_map(t_mapLayout *map_layout)
{
    int **visited_map;
    int row;
    int col;

    visited_map = malloc(sizeof(int *) * map_layout->row_count);
    if (!visited_map)
        perror_with_exit(1, "Memory allocation error.");
    row = 0;
    while (row < map_layout->row_count)
    {
        visited_map[row] = malloc(sizeof(int) * map_layout->col_count);
        if (!visited_map[row])
        {
            while (row >= 0)
            {
                row--;
                free(visited_map[row]);
            }
            free(visited_map);
        }
        col = 0;
        while (col < map_layout->col_count)
        {
            visited_map[row][col] = 0;
            col++;
        }
        row++;
    }
    return (visited_map);
}


static t_mapTraversal *init_traversal_data(void)
{
    t_mapTraversal *traversal_data;

    traversal_data = malloc(sizeof(t_mapTraversal));
    if (!traversal_data)
        perror_with_exit(1, "Memory allocation error.");
    traversal_data->collectibles_found = 0;
    traversal_data->exit_found = 0;
    return (traversal_data);
}


static void dfs(int row, int col, char **map, int **visited,
    t_mapTraversal *traversal_data)
{
    char cell;

    cell = map[row][col];
    if (cell == '1' || visited[row][col])
        return ;
    else if (cell == 'E')
        traversal_data->exit_found = 1;
    else if (cell == 'C')
        traversal_data->collectibles_found += 1;
    visited[row][col] = 1;
    dfs(row - 1, col, map, visited, traversal_data);
    dfs(row, col - 1, map, visited, traversal_data);
    dfs(row + 1, col, map, visited, traversal_data);
    dfs(row, col + 1, map, visited, traversal_data);
}


void check_map_layout(t_mapLayout *map_layout)
{
    int **visited;
    t_mapTraversal *traversal_data;

    visited = create_visited_map(map_layout);
    traversal_data = init_traversal_data();
    dfs(map_layout->player_pos->row, map_layout->player_pos->col,
        map_layout->map, visited, traversal_data);
    if (!traversal_data->exit_found)
        perror_with_exit(1, "Map does not have an exit path.");
    if (traversal_data->collectibles_found != map_layout->collectibles_count)
        perror_with_exit(1, "Not all collectibles on the map are reachable.");
}
