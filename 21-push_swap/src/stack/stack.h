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

    t_stack *create_stack(int *values, int values_count);
    t_stack *copy_stack(t_stack *stack);
    t_double_stack *create_double_stack(t_stack **stack_a, t_stack **stack_b);
    void deallocate_stack(t_stack **stack);
    int find_min(t_stack *stack);
    int find_max(t_stack *stack);
    int find_len(t_stack *stack);
    int find_mean(t_stack *stack);
    t_stack *find_last(t_stack *stack);
    int is_sorted(t_stack *stack);
    int is_in_order(t_stack *stack);
#endif