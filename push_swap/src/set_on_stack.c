#include "push_swap.h"

void    set_on_stack(t_stack **a, int *values, int len)
{
    while (--len >= 0)
    {    
        if (!ft_stack_unshift(a, values[len]))
        {
            ft_stack_destroy(a);
            exit(1);
        }
    }
    // ft_stack_revrotate(a);
    // ft_stack_rotate(a);
    
    
    // ft_putstr_fd(1, "good\n");
}