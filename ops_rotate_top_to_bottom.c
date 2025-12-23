#include "push_swap.h"

static void rotate(t_stack *s)
{
    t_node *first;
    t_node *last;

    if (s->size < 2)
        return; // no effect if stack has 0 or 1 element

    first = s->top;       // store current top node
    s->top = first->next; // second node becomes new top
    first->next = NULL;   // detach old top from the list

    last = s->top; // start from new top
    while (last->next)
        last = last->next; // walk to the last node

    last->next = first; // move old top to the bottom
}

void ra(t_stack *a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
