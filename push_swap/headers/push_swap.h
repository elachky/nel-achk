#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>

# include "ft_utils.h"
# include "ft_stack.h"


int     check_args(int, char **);
void    set_on_stack(t_stack **, int, char **);
void    push_swap_sort(t_stack **, t_stack **, int);
void    next_operations(t_stack **, t_stack **);

#endif
