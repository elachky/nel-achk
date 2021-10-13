#include "ft_stack.h"

void ft_stack_rotate(t_stack **a)
{
    t_stack *tmp;

    if (*a && (*a)->next)
    {
        tmp = *a;
        *a = (*a)->next;
        ft_stack_push(a, tmp->data);
        free(tmp);
    }
}

void ft_stack_rrotate(t_stack **a, t_stack **b)
{
    ft_stack_rotate(a);
    ft_stack_rotate(b);
}