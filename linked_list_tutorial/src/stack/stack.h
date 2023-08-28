#ifndef STACK_STACK_H
    #define STACK_STACK_H

    #include <stdlib.h>

    typedef struct s_stack
    {
        int value;
        struct s_stack *next;
    } t_stack;

    typedef struct s_double_stack {
        struct s_stack **a;
        struct s_stack **b;
    } t_double_stack;

    typedef struct s_stack_params {
        int get_min;
        int med;
        int max;
        int len;
    } t_stack_params;

    t_stack *create_node(int value);
    void insert_node_beginning(t_stack **root, int value);
    void insert_node_after(t_stack *node, int value);
    void insert_node_end(t_stack **root, int value);
    void remove_node(t_stack **root, int value);
    void deallocate_stack(t_stack **root);
    void reverse_stack(t_stack **root);
    int find_min(t_stack *stack);
    int find_max(t_stack *stack);
    int find_len(t_stack *stack);
    int find_value_index(t_stack *stack, int value);
    int is_first(t_stack *stack, int value);
    int is_ready_for_push(t_stack *stack, int value);
    t_double_stack *create_double_stack(t_stack **stack_a, t_stack **stack_b);
#endif