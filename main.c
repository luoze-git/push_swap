#include "push_swap.h"

int main(int argc, char **argv)
{
    int size;
    t_stack a;
    t_stack b;
    int *int_list;
    // parse -> returned the parsed int * with size
    int_list = parse_integer_input(argc, argv, &size);
    normalize_values(int_list, size);

    // build stack
    stack_builder(&a, int_list, size, 'a');
    stack_builder(&b, NULL, 0, 'b');
    free(int_list);
    dispatch_sort(&a, &b);
    free_stack(&a);
    free_stack(&b);

    return 0;
}