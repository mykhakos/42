#include "sorter.h"


void sort(t_stack **stack_a, t_stack **stack_b)
{
    int len_a;

    if (!is_in_order(*stack_a))
    {
    len_a = find_len(*stack_a);
    if (len_a == 3)
        sort_3(stack_a);
    else if (len_a > 3 && len_a <= 6)
        sort_4_to_6(stack_a, stack_b);
    else if (len_a > 6)
        sort_7_plus(stack_a, stack_b);
    }
    rot_a_until_min_a_is_first(stack_a, stack_b);
}