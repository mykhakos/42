# include "sorter.h"


int min_value(int val1, int val2)
{
    if (val1 < val2)
        return (val1);
    return (val2);
}

t_rot_ops *inst_rot_ops(int ra, int rb, int rra, int rrb)
{
    t_rot_ops *ops;

    ops = malloc(sizeof(t_rot_ops));
    if (ops == NULL)
        return (NULL);
    ops->rr = min_value(ra, rb);
    ops->ra = ra - ops->rr;
    ops->rb = rb - ops->rr;
    ops->rrr = min_value(rra, rrb);
    ops->rra = rra - ops->rrr;
    ops->rrb = rrb - ops->rrr;
    ops->total = ops->ra + ops->rb + ops->rr + ops->rra + ops->rrb + ops->rrr;
    return (ops);
}
