#include "minitalk.h"

int main (void)
{
	int pid;
	struct sigaction sa;

	pid = (int)getpid();
	ft_putnbr(pid);
	ft_putchar_fd(1, '\n');
	sa.sa_sigaction = &decode;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return 0;

}