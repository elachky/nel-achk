#include "ft_stack.h"

void    ft_stack_swap(t_stack **a)
{
    t_stack *head;

    head = (*a)->next;
    if (*a && (*a)->next)
    {
        (*a)->next = (*a)->next->next;
        ft_stack_unshift(a, head->data);
        free(head);
    }
}

void ft_stack_sswap(t_stack **a, t_stack **b)
{
    ft_stack_swap(a);
    ft_stack_swap(b);
}