#include "push_swap.h"


void dispatch_sort(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
        return;
    if (a->size <= 1)
        return;
    sort_big(a, b);
    return;
}

int is_sorted(t_stack *a)
{
    t_node *cur;

    if (a->size < 2)
        return 1;               // empty or single-element stack is sorted

    cur = a->top;               // start from top of stack
    while (cur->next)
    {
        if (cur->value > cur->next->value)
            return 0;           // found a descending pair → not sorted
        cur = cur->next;        // move to next node
    }
    return 1;                   // reached end with no violations → sorted
}
