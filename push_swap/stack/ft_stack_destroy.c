#include "ft_stack.h"

void    ft_stack_destroy(t_stack **s)
{
    t_stack *temp;

    temp = *s;
    while (*s)
    {
        temp = *s;
        *s = (*s)->next;
        free(temp);
    }
}