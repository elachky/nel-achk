/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:49:05 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/21 22:33:51 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	test_precision(char *fmt, t_specif *flags, va_list args, int *j)
{
	if (fmt[*j] == '.')
	{
		(*j)++;
		flags->precision = 0;
		if (fmt[*j] == '*')
		{
			flags->precision = va_arg(args, int);
			(*j)++;
		}
		else
			while (ft_isdigit(fmt[*j]))
				flags->precision = flags->precision * 10 + fmt[(*j)++] - '0';
	}
}
