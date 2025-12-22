#include "push_swap.h"

// internal swap func
static void swap(t_stack *s)
{
    t_node *first;
    t_node *second;

    if (s->size < 2)
        return;
    first = s->top;
    second = first->next;
    first->next = second->next; // relink only the next part
    second->next = first;
    s->top = second; // update the head node
}

void sa(t_stack *a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    swap(b);
    write(1, "sb\n", 3);
}
