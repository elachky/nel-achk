#include "ft_stack.h"

int ft_stack_max(t_stack *s)
{
    int max;

    max = INT_MIN;
    while (s)
    {
        if (max < s->data)
            max = s->data;
        s = s->next;
    }
    return (max);
}