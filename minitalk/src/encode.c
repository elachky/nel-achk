#include "minitalk.h"

void handle(int sig)
{
    if (sig != SIGUSR2)
    {
        exit(EXIT_FAILURE);
        ft_putstr_fd(2,"error ack");
    }
}

void    encode(int pid, char *msg)
{
    int bit;
    int i;
    int j;

    i = 0;
    if (signal(SIGUSR1, &handle) < 0 
        || signal(SIGUSR2, &handle) < 0)
    {
        ft_putstr_fd(2, "signal Error");
        exit(EXIT_FAILURE);
    }
    while (msg[i])
    {
        bit = 1;
        j = 0;
        while (j < 8)
        {
            if (msg[i] & bit)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            bit *= 2;
            usleep(75);
            while(1)
                pause(); //setitimer() for timeout
            j++;
        }
        i++;
    }
}