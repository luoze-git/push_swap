#include "push_swap.h"

void sort_big(t_stack *a, t_stack *b)
{
    int bit;
    int max_bits;
    int i;
    int size;

    size = a->size;
    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;

    bit = 0;
    while (bit < max_bits)
    {
        i = 0;
        while (i < size)
        {
            if (((a->top->value >> bit) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            i++;
        }
        while (b->size > 0)
            pa(a, b);
        bit++;
    }
}
