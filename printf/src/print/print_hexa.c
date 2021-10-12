/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsi <rsi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:07:13 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/03 18:53:22 by rsi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	print_hexa_moins(char **str, t_specif *flags, char c, int j)
{
	if (c == 'p')
		ft_putstr_fd("0x", 1);
	put('0', flags->precision - ft_strlen(*str));
	ft_putstr_fd(*str, 1);
	put(' ', flags->width - j);
}

void	print_hexa_zero(char **str, t_specif *flags, char c, int i)
{
	if (c == 'p')
		ft_putstr_fd("0x", 1);
	put('0', flags->width - i);
	ft_putstr_fd(*str, 1);
}

void	print_hexa_else(char **str, t_specif *flags, char c, int j)
{
	put(' ', flags->width - j);
	if (c == 'p')
		ft_putstr_fd("0x", 1);
	put('0', flags->precision - ft_strlen(*str));
	ft_putstr_fd(*str, 1);
}

int		print_hexa(char **str, t_specif *flags, char c)
{
	int i;
	int j;

	if (**str == '0' && flags->precision == 0)
		**str = '\0';
	i = ft_strlen(*str);
	j = ft_max(flags->precision, i);
	if (c == 'p')
	{
		j = ft_max(flags->precision, i) + 2;
		i += 2;
	}
	if (c == 'X')
		*str = ft_toupper_str(*str);
	if (flags->pad_moins == 1)
		print_hexa_moins(str, flags, c, j);
	else if (flags->pad_zero == 1 && flags->precision <= -1)
		print_hexa_zero(str, flags, c, i);
	else
		print_hexa_else(str, flags, c, j);
	return (ft_max(j, flags->width));
}
