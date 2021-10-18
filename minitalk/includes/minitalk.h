#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
#include <string.h>

# include "ft_libft.h"

void    decode(int signo, siginfo_t *siginfo, void *context);
void    encode(int, char *);

#endif