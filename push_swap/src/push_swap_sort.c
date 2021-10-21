#include "push_swap.h"

static void sort_three(t_stack **a)
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
	if ((first == max && second != min) 
		|| (third == max && first != min) 
		|| (second == max && third != min))
	{
		ft_stack_swap(a);
		ft_putstr_fd(1, "sa\n");
	}
}

static void ft_get_lis_indexs(t_stack *s, int **arr, int len)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (j < len)
	{
		i = 0;
		while (i < j)
		{
			if (ft_stack_value_at(s, i) < ft_stack_value_at(s, j) && arr[0][i] + 1 > arr[0][j])
				arr[0][j] = arr[0][i] + 1;
			i++;
		}
		j++;
	}
}

static t_stack *get_lis(t_stack *a, int len)
{
	t_stack *lis;
	int *arr;
	int max_arr;
	int prev_last_index;
	int last_index;

	prev_last_index = len;
	lis = NULL;
	if (!(arr = ft_calloc(len)))
		return (NULL);
	ft_get_lis_indexs(a, &arr, len);
	max_arr = ft_max_arr(arr, len) + 1;
	while (max_arr)
	{
		last_index = ft_last_index(arr, --max_arr, prev_last_index);
		if (!ft_stack_unshift(&lis, ft_stack_value_at(a, last_index)))
		{
			ft_stack_destroy(&lis);
			break;
		}	
		prev_last_index = last_index;
	}
	free(arr);
	return lis;
}

void push_swap_sort(t_stack **a, t_stack **b, int len)
{
	t_stack *lis;
	
	if (len == 3)
		sort_three(a);
	if (!(lis = get_lis(*a, len)))
	{
		ft_stack_destroy(a);
		exit(EXIT_FAILURE);
	}
	// push to b while a.len > lis.len and
	while (ft_stack_len(*a) > ft_stack_len(lis))
	{
		if (ft_stack_index_of(lis, (*a)->data))
		{
			ft_stack_pushto(a, b);
			ft_putstr_fd(1, "pb\n");
		}
		else
		{
			ft_stack_rotate(a);
			ft_putstr_fd(1, "ra\n");
		}
	}
	
	free(lis); // is this free correct ##to review##
	// printf("%d ", ft_stack_value_at(*a, 12));
	// while (*b)//need to add after push unsorted elements to stack b
	// {
		// next_operations(a, b);
	// }
		
	// while (lis)
	// {
	// 	printf("%d ", lis->data);
	// 	lis = lis->next;
	// }
	printf("\n");
}