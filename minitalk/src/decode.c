#include "minitalk.h"

void    decode(int signo, siginfo_t *siginfo, void *context)
{
    static char c = 0;
    static int  bit = 1;
    static int  i = 0;

    context = NULL;
    if (i < 8)
    {
        if (signo == SIGUSR2)
            c |= bit;
        bit *= 2;
        i++;
        kill(siginfo->si_pid, SIGUSR2);
    }
    if (i == 8)
    {
        ft_putchar_fd(1, c);
        bit = 1;
        c = 0;
        i = 0;
    }

}