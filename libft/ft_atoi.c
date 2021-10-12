/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:02:37 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/08 16:30:33 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_space(char c)
{
	if (c == '\n' || c == '\r' || c == '\t' ||
			c == ' ' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int				fact;
	unsigned long	result;

	fact = 1;
	result = 0;
	while (test_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			fact = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + *str++ - '0';
		if (result > LONG_MAX)
		{
			if (fact == 1)
				return (-1);
			return (0);
		}
	}
	return ((int)(result * fact));
}
