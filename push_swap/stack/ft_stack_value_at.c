#include "ft_stack.h"

int ft_stack_value_at(t_stack * s, int index)
{
    int i;

    i = 0;
    while (i != index)
    {
        s = s->next;
        i++;
    }
    return (s->data);
}