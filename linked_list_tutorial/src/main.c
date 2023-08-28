#include "main.h"
#include <stdio.h>


int main(int argc, char * argv[])
{
    t_stack *root;
    t_stack *curr_node;

    root = create_node(1);

    insert_node_end(&root, 2);
    insert_node_end(&root, 3);
    curr_node = root;
    while (curr_node != NULL)
    {
        printf("%d\n", curr_node->value);
        curr_node = curr_node->next;
    }
    deallocate_stack(&root);
    return (0);
}