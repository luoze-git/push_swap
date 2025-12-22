#include "push_swap.h"

void stack_init(t_stack *s, char name)
{
    s->top = NULL;
    s->size = 0;
    s->name = name;
}

// create a new node with a given value
t_node *node_new(int value)
{
    t_node *n;

    n = malloc(sizeof(t_node));
    if (!n)
        return NULL;
    n->value = value;
    n->index = -1; 
    n->next = NULL;
    return n;
}

// put a given node to the top of a stack
// mini-step 1/2 for ops
void stack_push(t_stack *s, t_node *n)
{
    n->next = s->top;
    s->top = n;
    s->size++;
}

// pop a node from a stack
// mini-step 2/2 for ops
t_node *stack_pop(t_stack *s)
{
    t_node *n;

    if (s->size == 0)
        return NULL;
    n = s->top;
    s->top = n->next;
    n->next = NULL;
    s->size--;
    return n;
}
