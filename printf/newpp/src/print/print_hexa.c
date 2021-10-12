/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:18:44 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 17:31:16 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	hexa_left(char **str, t_specif *flags, int len, char c)
{
	int i;

	i = ft_max(len, flags->precision);
	print_pad(flags->precision - len, '0');
	if (c == 'X')
		*str = ft_toupper_str(*str);
	ft_putstr_fd(*str, 1);
	print_pad(flags->width - i, ' ');
	free(*str);
	return (ft_max(flags->width, i));
}

int	hexa_noleft(char **str, t_specif *flags, int len, char c)
{
	if (flags->pad_zero == 1 && flags->precision < 0)
		print_pad(flags->width - len, '0');
	else
	{
		print_pad(flags->width - ft_max(flags->precision, len), ' ');
		print_pad(flags->precision - len, '0');
	}
	if (c == 'X')
		*str = ft_toupper_str(*str);
	ft_putstr_fd(*str, 1);
	free(*str);
	return (ft_max(flags->width, len));
}

int	hexa_precision(char **str, t_specif *flags, int len, char c)
{
	if (flags->precision == 0 && *str[0] == '0')
	{
		free(*str);
		return (0);
	}
	print_pad(flags->precision - len, '0');
	if (c == 'X')
		*str = ft_toupper_str(*str);
	ft_putstr_fd(*str, 1);
	free(*str);
	return (ft_max(flags->precision, len));
}

int	print_hexa(va_list args, t_specif *flags, int *j, char c)
{
	char	*str;
	int		len;

	(*j)++;
	str = ft_itoa_hexa(va_arg(args, unsigned int));
	len = ft_strlen(str);
	if (flags->width > flags->precision && flags->width >= len)
	{
		if (flags->precision == 0 && str[0] == '0')
		{
			free(str);
			return (print_pad(flags->width, ' '));
		}
		if (flags->pad_moins == 1)
			return (hexa_left(&str, flags, len, c));
		else
			return (hexa_noleft(&str, flags, len, c));
	}
	else
		return (hexa_precision(&str, flags, len, c));
	return (0);
}
