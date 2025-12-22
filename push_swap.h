#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
    char    name;
}   t_stack;


void    stack_init(t_stack *s, char name);
t_node  *node_new(int value);

void    stack_push(t_stack *s, t_node *n);
t_node  *stack_pop(t_stack *s);


/* push */
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

/* swap */
void    sa(t_stack *a);
void    sb(t_stack *b);


#endif
