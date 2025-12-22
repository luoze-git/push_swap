#include "push_swap.h"


void dispatch_sort(t_stack *a, t_stack *b)
{

    int n;

    if (is_sort(a))
        return;
    n = stack_size(a);

    if (n <= 1)
        return;
    if (n <= 3)
        return (sort_3());
    if (n <= 5)
        return (sort_5());
    sort_big(a, b);
    return;
}