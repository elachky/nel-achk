#include "ft_stack.h"

int ft_stack_value_at(t_stack *s, int index)
{
    int i;
    int len;

    len = ft_stack_len(s);
    if (index > len)
        return (-1);
    if (index < 0)
        index = len + index;
    i = 0;
    while (i != index && s)
    {
        s = s->next;
        i++;
    }
    return (s->data);
}