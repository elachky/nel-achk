#include "push_swap.h"

static void     sort_three(t_stack **a)
{
    int max;
    int min;
    int first;
    int second;
    int third;

    max = ft_stack_max(*a);
    min = ft_stack_min(*a);
    first = ft_stack_value_at(*a, 0);
    second = ft_stack_value_at(*a, 1);
    third = ft_stack_value_at(*a, 2);
    if ((first == max && second == min)
        || (third == max && first == min)
        || (second == max && third == min))
    {
        ft_stack_swap(a);
        ft_putstr_fd(1, "sa");
    }
}

static t_stack  *get_lis(t_stack *a, int len)
{
    // t_stack *lis;
    int     i;
    int     j;
    int *arr;

    if (!(arr = ft_calloc(len)))
        return (NULL);
    i = 0;
    j = 1;
    while (j < len)
    {
        i = 0;
        while (i < j)
        {
            if (ft_stack_value_at(a, i) < ft_stack_value_at(a, j)
                && arr[i] + 1 > arr[j])
                arr[j] = arr[i] + 1;
            i++;
        }
        j++;
    }
    for(i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return NULL;
}

void    push_swap_sort(t_stack **a,/* t_stack **b,*/ int len)
{
    t_stack *lis;

    if (len == 3)
        sort_three(a);
    if (!(lis = get_lis(*a, len)))
    {
        ft_stack_destroy(a);
        exit(EXIT_FAILURE);
    }
    free(lis);
    
}