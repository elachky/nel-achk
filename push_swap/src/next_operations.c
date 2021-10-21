#include "push_swap.h"

int find_place(t_stack *s, int value) //need more check here XD
{
	int	pos_max;
	int i;
	int len;

	i = 0;
	len = ft_stack_len(s);
	while (s->next)
	{
		if (ft_stack_value_at(s, i) < value
			&& ft_stack_value_at(s, i + 1) > value)
			return (i);
		if (ft_stack_value_at(s, -i) < value
			&& ft_stack_value_at(s, -i + 1) > value)
			return (i);
		i++;
	}
	pos_max = ft_stack_index_of(s, ft_stack_max(s)) + 1;
	if (pos_max == len)
		pos_max = 0;
	if (pos_max > len - pos_max)
		pos_max = -(len - pos_max);
	return (pos_max);
}

int	count_ops(int pos_a, int pos_b) // not working yet X uncheckd X
{
	if (pos_a * pos_b > 0)
		return (ft_max(ft_abs(pos_a), ft_abs(pos_b)));
	return (ft_abs(pos_a) + ft_abs(pos_b));
}
// int	*find_best()

// void    next_operations(t_stack **a, t_stack **b)
// {
	
// }