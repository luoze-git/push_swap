#include "push_swap.h"

// return the scope of bits through the largest value , ie. the largest index or the size after normalization
static int get_max_bits(int max_value)
{
    int bits;

    bits = 0;
    while ((max_value >> bits) != 0)
        bits++;
    return bits;
}

// outer loop : per bit;
// inner loop 1: per element in the stack a
// idea: push the 0s to b , after loop 1, push them back to a. this makes 0s, the smaller ones, stay on top.
void sort_big_radix(t_stack *a, t_stack *b)
{
    int max_bits;
    int bit;
    int i;
    int size;

    size = a->size;
    max_bits = get_max_bits(size - 1);
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
