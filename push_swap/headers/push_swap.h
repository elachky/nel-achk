#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

# include "ft_utils.h"
# include <stdio.h>

# define P_MAX_INT 2147483647
# define P_MIN_INT -2147483648

typedef struct  s_stack{
    int             data;
    struct s_stack  *next;
}               t_stack;

int check_args(int, char **);
int *tokenize(int, char **);

#endif
