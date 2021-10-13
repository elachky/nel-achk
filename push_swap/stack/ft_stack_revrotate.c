#include "ft_stack.h"

void ft_stack_revrotate(t_stack **a)
{
	t_stack		*last;
	t_stack		*tmp;

	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = (*a);
	*a = last;
}

void ft_stack_rrevrotate(t_stack **a, t_stack **b)
{
    ft_stack_revrotate(a);
    ft_stack_revrotate(b);
}