#include "ft_stack.h"

void    ft_stack_pushto(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (*a)
    {
        tmp = *a;
        *a = (*a)->next;
        ft_stack_unshift(b, tmp->data);
        free(tmp);
    }
}