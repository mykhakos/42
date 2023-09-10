# include "sorter.h"


t_rot_ops *find_opt_rot_variant(t_rot_ops **rot_variants)
{
    t_rot_ops *rots_opt;
    t_rot_ops **rot_variants_ptr;

    if (!rot_variants || !rot_variants[0])
        return (NULL);
    rot_variants_ptr = rot_variants;
    rots_opt = *rot_variants_ptr;
    rot_variants_ptr += 1;
    while (*rot_variants_ptr != NULL)
    {
        if ((*rot_variants_ptr)->total < rots_opt->total)
        {
            free(rots_opt);
            rots_opt = *rot_variants_ptr;
        }
        else
        {
            free(*rot_variants_ptr);
        }
        rot_variants_ptr += 1;
    }
    free(rot_variants);
    return (rots_opt);
}

t_rot_ops *find_opt_rots_push_value_to_a(t_stack *stack_a,
                                         t_stack *stack_b,
                                         int value)
{
    t_rot_ops rot_ops_all;
    t_rot_ops **rot_variants;

    rot_variants = malloc(sizeof(t_rot_ops *) * 5);
    if (!rot_variants)
        return (NULL);
    rot_ops_all.ra = rots_direct(stack_a, value, is_ready_for_push);
    rot_ops_all.rra = rots_reverse(stack_a, value, is_ready_for_push);
    rot_ops_all.rb = rots_direct(stack_b, value, is_first);
    rot_ops_all.rrb = rots_reverse(stack_b, value, is_first);
    rot_variants[0] = create_rot_ops(rot_ops_all.ra, rot_ops_all.rb, 0, 0);
    rot_variants[1] = create_rot_ops(rot_ops_all.ra, 0, 0, rot_ops_all.rrb);
    rot_variants[2] = create_rot_ops(0, rot_ops_all.rb, rot_ops_all.rra, 0);
    rot_variants[3] = create_rot_ops(0, 0, rot_ops_all.rra, rot_ops_all.rrb);
    rot_variants[4] = NULL;
    return (find_opt_rot_variant(rot_variants));
}

t_rot_ops *find_opt_rots_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
    t_rot_ops *rots_opt;
    t_rot_ops *rots_temp;
    t_stack *stack_b_ptr_cpy;

    rots_opt = find_opt_rots_push_value_to_a(stack_a, stack_b, stack_b->value);
    stack_b_ptr_cpy = stack_b->next;
    while (stack_b_ptr_cpy != NULL)
    {
        rots_temp = find_opt_rots_push_value_to_a(
            stack_a, stack_b, stack_b_ptr_cpy->value);
        if (rots_temp->total < rots_opt->total)
        {
            free(rots_opt);
            rots_opt = rots_temp;
        }
        else
        {
            free(rots_temp);
        }
        stack_b_ptr_cpy = stack_b_ptr_cpy->next;
    }
    return (rots_opt);
}

t_rot_ops *find_opt_rots_min_a_is_first(t_stack *stack_a)
{
    int min_value;
    int ra_count;
    int rra_count;

    min_value = find_min(stack_a);
    ra_count = rots_direct(stack_a, min_value, is_first);
    rra_count = rots_reverse(stack_a, min_value, is_first);
    if (ra_count <= rra_count)
        return (create_rot_ops(ra_count, 0, 0, 0));
    return (create_rot_ops(0, 0, rra_count, 0));
}