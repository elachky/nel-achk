#include "minitalk.h"

int main (int ac, char **av)
{
    int pid;

    if (ac != 3 || !ft_isstrdigit(av[1])
        || kill(ft_atoi(av[1]), 0))
    {
        ft_putstr_fd(2, "Error");
        exit(EXIT_FAILURE);
    } 
    else
    {
        pid = ft_atoi(av[1]);
        encode(pid, av[2]);
    }  
    return 0;
}