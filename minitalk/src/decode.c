/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:12:35 by nel-achk          #+#    #+#             */
/*   Updated: 2021/10/19 15:13:47 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decode(int signo, siginfo_t *siginfo, void *context)
{
	static char	c = 0;
	static int	bit = 0;
	static int	c_pid = 0;
	static int	i = 0;

	(void)context;
	if (siginfo->si_pid)
		c_pid = siginfo->si_pid;
	if (i < 8)
	{
		if (signo == SIGUSR2)
			c |= 1 << bit;
		bit++;
		i++;
		usleep(30);
		kill(c_pid, SIGUSR2);
	}
	if (i == 8)
	{
		ft_putchar_fd(1, c);
		bit = 0;
		c = 0;
		i = 0;
	}
}
