/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:02:37 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/21 22:22:25 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	int	test_space(char c)
{
	if (c == '\n' || c == '\r' || c == '\t' ||
			c == ' ' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static	int	ft_sign_test(const char **str)
{
	int	fact;

	fact = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			fact = -1;
		(*str)++;
	}
	return (fact);
}

int			ft_atoi(const char *str)
{
	int				fact;
	unsigned long	result;

	result = 0;
	if (!str)
		return (0);
	while (test_space(*str))
		str++;
	fact = ft_sign_test(&str);
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
