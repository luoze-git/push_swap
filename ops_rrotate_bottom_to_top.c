#include "push_swap.h"

static void reverse_rotate(t_stack *s)
{
    t_node *prev;
    t_node *cur;

    if (s->size < 2)
        return; // no effect if stack has 0 or 1 element

    prev = NULL;
    cur = s->top; // start from top of the stack

    while (cur->next)
    {
        prev = cur;      // keep track of node before cur
        cur = cur->next; // move to next node
    }

    prev->next = NULL;  // detach cur node from its previous position
    cur->next = s->top; // link cur node before current top
    s->top = cur;       // update top to old cur node
}

void rra(t_stack *a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
