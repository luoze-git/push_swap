#include "push_swap.h"

// naive selection sort - compare each to all the others
static void sort_int_array(int *arr, int n)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < n - 1)
    {
        j = i + 1;
        while (j < n)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

static int find_index(int *sorted, int n, int value)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (sorted[i] == value)
            return i;
        i++;
    }
    return -1; // should never happen / just syntax requirement
}

void normalize_values(int *int_list, int nint)
{
    int *sorted;
    int i;

    sorted = malloc(sizeof(int) * nint);
    if (!sorted)
        set_stderr_exit();

    i = 0;
    // copy the int list
    while (i < nint)
    {
        sorted[i] = int_list[i];
        i++;
    }

    // sort it inplace - the index of INTs is what matters now in "sorted"
    sort_int_array(sorted, nint);

    i = 0;
    // update the original list with their rank(the index in ascending order)
    // original value : index is one to one.so this works . Algorithm!
    while (i < nint)
    {
        int_list[i] = find_index(sorted, nint, int_list[i]);
        i++;
    }

    free(sorted);
}
