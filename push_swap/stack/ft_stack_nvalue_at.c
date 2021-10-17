#include "ft_stack.h"

int ft_stack_nvalue_at(t_stack *s, int index)
{
    int i;
    int len;

    len = ft_stack_len(s);
    i = -(len / 2);
    while (s->next && i != index)
    {
        s = s->next;
        i++;
    }
    return (s->data);
}