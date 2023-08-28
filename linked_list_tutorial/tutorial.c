#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
   int x;
   struct Node *next; 
} Node;


void insert_end(Node **root, int value)
{
    Node *new_node;
    Node *curr_node;

    new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        exit(1);
    new_node->next = NULL;
    new_node->x = value;
    if (*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        curr_node = *root;
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

void insert_beginning(Node **root, int value)
{
    Node *new_node;
    Node *curr_node;

    new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        exit(1);
    new_node->next = *root;
    new_node->x = value;
    *root = new_node;
}

void insert_after(Node *node, int value)
{
    Node *new_node;
    Node *curr_node;

    new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        exit(1);
    new_node->next = node->next;
    new_node->x = value;
    node->next = new_node;
}

void remove_node(Node **root, int value)
{
    Node *node_to_remove;
    Node *curr_node;

    if (*root == NULL)
        return ;
    if ((*root)->x == value)
    {
        node_to_remove = *root;
        *root = (*root)->next;
        free(node_to_remove);
        return ;
    }
    curr_node = *root;
    while (curr_node->next != NULL)
    {
        if (curr_node->next->x == value)
        {
            node_to_remove = curr_node->next;
            curr_node->next = curr_node->next->next;
            free(node_to_remove);
            return ;
        }
        curr_node = curr_node->next;
    }
}

void reverse(Node **root)
{
    Node *prev;
    Node *curr;
    Node *next;

    prev = NULL;
    curr = *root;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev;
}


void deallocate(Node **root)
{
    Node *curr_node;
    Node *tmp;

    curr_node = *root;
    while (curr_node != NULL)
    {
        tmp = curr_node->next;
        free(curr_node);
        curr_node = tmp;
    }
}

int main(int argc, char * argv[])
{
    Node *root;
    Node *curr_node;

    root = malloc(sizeof(Node));
    if (root == NULL)
        exit(1);
    root->x = 1;
    root->next = NULL;

    insert_end(&root, 2);
    insert_end(&root, 3);
    insert_after(root->next->next, 7);
    reverse(&root);
    curr_node = root;
    while (curr_node != NULL)
    {
        printf("%d\n", curr_node->x);
        curr_node = curr_node->next;
    }
   
    deallocate(&root);
    return (0);
}