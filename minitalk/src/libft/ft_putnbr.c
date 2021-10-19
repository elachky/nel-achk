/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:23:16 by nel-achk          #+#    #+#             */
/*   Updated: 2021/10/19 15:25:00 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd(1, '-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar_fd(1, nbr % 10 + 48);
}
