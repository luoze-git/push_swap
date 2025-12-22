# include "p_s.h"

void    stack_init(t_stack *s, char name)
{
    s->top = NULL;
    s->size = 0;
    s->name = name;
}
