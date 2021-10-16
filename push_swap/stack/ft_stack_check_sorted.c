#include "ft_stack.h"

int ft_stack_check_sorted(t_stack *a)
{
    while (a->next)
    {    
        if (a->data > a->next->data)
            return (0);
        a = a->next;
    }
    return (1);
}