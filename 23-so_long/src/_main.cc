#include "../include/so_long.h"


int main(int argc, char **argv)
{
    int map_fd;
    char *row_chars;
    t_mapRow *map_rows;
    t_mapLayout *map_layout;

    if (argc != 2)
    {
        perror("Provide a .ber map file path.\n");
        return 0;        
    }
    map_fd = open(argv[1], O_RDONLY);
    if (map_fd == -1)
    {
        perror("Error occred while opening the map file.");
        return 1;
    }
    row_chars = get_next_line(map_fd);
    if (!row_chars)
        perror_with_exit(1, ".ber map file is empty.");
    map_rows = NULL;
    while (row_chars != NULL)
    {
        append_row(&map_rows, ft_strtrim(row_chars, "\n"));
        row_chars = get_next_line(map_fd);
    }
    map_layout = check_map_rows(map_rows);
    create_map_from_list(map_layout, map_rows);

    check_map_layout(map_layout);
    close(map_fd);
}