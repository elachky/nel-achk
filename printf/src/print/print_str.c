/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsi <rsi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:16:29 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/10 20:10:32 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	ft_putstr_len(char *str, int len)
{
	while (len-- > 0 && *str)
		put(*str++, 1);
}

int		print_str(char **str, t_specif *flags, va_list args, int *j)
{
	int i;

	*str = va_arg(args, char*);
	if (!*str)
		*str = "(null)";
	i = ft_strlen(*str);
	if (flags->precision > -1)
		i = (flags->precision > i) ? i : flags->precision;
	if (flags->pad_moins == 1)
	{
		ft_putstr_len(*str, i);
		put(' ', flags->width - i);
	}
	else if (flags->pad_zero == 1)
	{
		put('0', flags->width - i);
		ft_putstr_len(*str, i);
	}
	else
	{
		put(' ', flags->width - i);
		ft_putstr_len(*str, i);
	}
	(*j)++;
	return (ft_max(i, flags->width));
}
