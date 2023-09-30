#include <fcntl.h> // For open
#include <unistd.h> // For close
#include "main.h"


int main(int argc, char **argv)
{
    int mapFileDescriptor;
    char *row_chars;
    t_mapRow *map_rows;
    t_mapLayout *map_layout;

    if (argc != 2)
    {
        perror("Provide a .ber map file path.\n");
        return 0;        
    }
    mapFileDescriptor = open(argv[1], O_RDONLY);
    if (mapFileDescriptor == -1)
    {
        perror("Error occred while opening the map file.");
        return 1;
    }
    row_chars = get_next_line(mapFileDescriptor);
    if (!row_chars)
        perror_with_exit(1, ".ber map file is empty.");
    map_rows = NULL;
    while (row_chars != NULL)
    {
        append_row(&map_rows, ft_strtrim(row_chars, "\n"));
        row_chars = get_next_line(mapFileDescriptor);
    }
    map_layout = check_map_rows(map_rows);
    create_map_from_list(map_layout, map_rows);

    check_map_layout(map_layout);
    close(mapFileDescriptor);
}