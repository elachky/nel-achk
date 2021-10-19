/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:16:21 by nel-achk          #+#    #+#             */
/*   Updated: 2021/10/19 15:17:14 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	pid;

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
	return (0);
}
