#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int process_file(int fd)
{
    char *line = NULL;
    printf("processing desciptor %i\n", fd);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("processing line: ");
        printf("%s", line);
        free(line);
        printf("done processing line\n");
    }
    printf("done processing desciptor %i\n", fd);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <filename1> [<filename2> ...]\n", argv[0]);
        return (1);
    }



    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
        int fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            continue;
        }

        printf("\nProcessing file: %s\n", argv[i]);
        int res = process_file(fd);
        printf("res: %i\n", res);
        printf("\nProcessing file: %s - done\n", argv[i]);
        close(fd);
        
    }

    return (0);
}
