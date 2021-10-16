#include "push_swap.h"

static void sort_three(t_stack **a)
{
    if ((*a)->data == 0)//to edit
    {
        ft_push_swap(a);
        ft_putstr_fd(1, "sa");
    }
}

void    push_swap_sort(t_stack **a, t_stack **b, int len)
{
    if (len == 3)
        sort_three(a);
    
    
}