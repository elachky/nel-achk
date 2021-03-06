#ifndef FT_stack_H
# define FT_stack_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>


typedef struct  s_stack{
	int             data;
	struct s_stack  *next;
}               t_stack;

t_stack *ft_stack_push(t_stack **, int);
t_stack *ft_stack_unshift(t_stack **, int);
void    ft_stack_destroy(t_stack **);
void    ft_stack_rotate(t_stack **);
void    ft_stack_rrotate(t_stack **, t_stack **);
void    ft_stack_revrotate(t_stack **a);
void    ft_stack_rrevrotate(t_stack **, t_stack **);
void    ft_stack_swap(t_stack **);
void    ft_stack_pushto(t_stack **, t_stack **);
int     ft_stack_len(t_stack *);
int     ft_stack_min(t_stack *);
int     ft_stack_max(t_stack *);
int     ft_stack_check_sorted(t_stack *);
int     ft_stack_value_at(t_stack *, int);
int     ft_stack_nvalue_at(t_stack *, int);
int     ft_stack_index_of(t_stack *s, int value);

#endif