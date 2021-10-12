/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsi <rsi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:18:31 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/03 17:54:09 by rsi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	print_int_moins(char *str, t_specif *flags, int j)
{
	if (*str == '-')
	{
		put('-', 1);
		str++;
	}
	put('0', flags->precision - ft_strlen(str));
	ft_putstr_fd(str, 1);
	put(' ', flags->width - j);
}

void	print_int_zero(char *str, t_specif *flags, int i)
{
	if (*str == '-')
	{
		put('-', 1);
		str++;
	}
	put('0', flags->width - i);
	ft_putstr_fd(str, 1);
}

int		print_int_result(char *str, t_specif *flags)
{
	int i;
	int j;

	if (*str == '0' && flags->precision == 0)
		*str = '\0';
	i = ft_strlen(str);
	j = ft_max(flags->precision, i);
	if (*str == '-')
		j = ft_max(flags->precision, i - 1) + 1;
	if (flags->pad_moins == 1)
		print_int_moins(str, flags, j);
	else if (flags->pad_zero == 1 && flags->precision <= -1)
		print_int_zero(str, flags, i);
	else
	{
		put(' ', flags->width - j);
		if (*str == '-')
		{
			put('-', 1);
			str++;
		}
		put('0', flags->precision - ft_strlen(str));
		ft_putstr_fd(str, 1);
	}
	return (ft_max(j, flags->width));
}

int		print_int(char **str, t_specif *flags, va_list args, char c)
{
	int i;

	i = 0;
	if (c == 'u')
		*str = ft_itoa_unsign(va_arg(args, unsigned int));
	else if (c == 'i' || c == 'd')
		*str = ft_itoa(va_arg(args, int));
	i += print_int_result(*str, flags);
	return (i);
}
