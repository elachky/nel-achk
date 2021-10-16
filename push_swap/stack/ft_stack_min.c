#include "ft_stack.h"

int ft_stack_min(t_stack *s)
{
    int min;

    min = INT_MAX;
    while (s)
    {
        if (min > s->data)
            min = s->data;
        s = s->next;
    }
    return (min);
}

//how to use 
// if (ft_stack_min(a) == INT_MIN && a)