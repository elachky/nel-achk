#ifndef FT_stack_H
# define FT_stack_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct  s_stack{
    int             data;
    struct s_stack  *next;
}               t_stack;

t_stack     *ft_stack_push(t_stack **, int);
t_stack     *ft_stack_unshift(t_stack **, int);
void        ft_stack_destroy(t_stack **);
void        ft_stack_rotate(t_stack **);
void        ft_stack_rrotate(t_stack **, t_stack **);
void        ft_stack_revrotate(t_stack **a);
void        ft_stack_rrevrotate(t_stack **, t_stack **);
void        ft_stack_swap(t_stack **);
void        ft_stack_pushto(t_stack **, t_stack **);
int         ft_stack_len(t_stack *);

#endif