#include <stdio.h>
#include "libft/libft.h"
#include "src/src.h"

void print_node_data(void *node) {
    node_t *actual_node = (node_t *)node;
    printf("%d \n", actual_node->data);
}


int main(int argc, char **argv) {
    node_t *head = NULL;
    node_t *new = NULL;
    int     new_content;

    if (argc == 1) {
        ft_putendl_fd("Provide a list of integer values separated by a whitespace", 1);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        if (!ft_isdigit(*argv[i])) {
            ft_putendl_fd("Error", 1);
            return 0;
        }
        else
        {
            new_content = ft_atoi(argv[i]);
            new = lstnew(new_content);
            //printf("%d\n", new->content);
            lstadd_front(&head, new);
        }
    }

    //ft_putendl_fd("OK", 1);
    while (head->next != NULL)
    {
        print_node_data(head);
        head = head->next;
    }
    return 0;
}