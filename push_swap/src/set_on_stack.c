#include "push_swap.h"

void    set_on_stack(t_stack **a, int len, char **argv)
{
    long temp;
    int i;

    while (--len)
    {
        temp = ft_atol(argv[len]);
        if (temp > INT_MAX || temp < INT_MIN)
        {
            ft_stack_destroy(a);
            ft_putstr_fd(STDERR_FILENO, "Error out of range\n");
            exit(EXIT_FAILURE);
        }
        ft_stack_unshift(a, (int)temp);
        i++;
    }
    if(ft_stack_check_sorted(*a))
    {
        ft_stack_destroy(a);
        exit(EXIT_SUCCESS);
    }
}