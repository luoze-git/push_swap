# include "p_s.h"

// internal func for pa/pb : push to a from b's top / push to b from a's top.
// static - cannot be called else where
static void push(t_stack *src, t_stack *dst)
{
    t_node *n;

    if (src->size == 0)
        return;
    n = stack_pop(src);
    stack_push(dst, n);
}

void    pa(t_stack *a, t_stack *b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void    pb(t_stack *a, t_stack *b)
{
    push(a, b);
    write(1, "pb\n", 3);
}




