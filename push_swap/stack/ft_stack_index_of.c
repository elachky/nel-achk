#include "ft_stack.h"

int ft_stack_index_of(t_stack *s, int value)
{
	int i;

	i = 0;
	while (s)
	{
		if (s->data == value)
			return i;
		s = s->next;
	}
	return (INT_MIN);
}