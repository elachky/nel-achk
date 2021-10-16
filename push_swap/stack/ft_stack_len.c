#include "ft_stack.h"

int  ft_stack_len(t_stack *a)
{
    int i;

    i = 0;
    while(a)
    {
        a = a->next;
        i++;
    }
    return i;
}