/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:14:25 by nel-achk          #+#    #+#             */
/*   Updated: 2021/10/19 15:15:32 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;
	int	bit;

	bit = 1;
	i = 0;
	while (i < 8)
	{
		usleep(75);
		if (c & bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		bit *= 2;
		i++;
	}
}

void	handle_ack(int signo)
{
	if (signo != SIGUSR2)
	{
		exit(EXIT_FAILURE);
		ft_putstr_fd(2, "error ack");
	}
}

void	encode(int pid, char *msg)
{
	int	i;

	i = -1;
	if (signal(SIGUSR1, &handle_ack) < 0
		|| signal(SIGUSR2, &handle_ack) < 0)
	{
		ft_putstr_fd(2, "signal Error");
		exit(EXIT_FAILURE);
	}
	while (msg[++i] != '\0')
		send_char(msg[i], pid);
	send_char(msg[i], pid);
}
