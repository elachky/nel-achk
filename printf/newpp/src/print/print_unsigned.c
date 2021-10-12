/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:21:00 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 17:33:24 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	unsigned_left(char **str, t_specif *flags, int len)
{
	int i;

	i = ft_max(len, flags->precision);
	print_pad(flags->precision - len, '0');
	ft_putstr_fd(*str, 1);
	print_pad(flags->width - i, ' ');
	free(*str);
	return (ft_max(flags->width, i));
}

int	unsigned_noleft(char **str, t_specif *flags, int len)
{
	if (flags->pad_zero == 1 && flags->precision < 0)
		print_pad(flags->width - len, '0');
	else
	{
		print_pad(flags->width - ft_max(flags->precision, len), ' ');
		print_pad(flags->precision - len, '0');
	}
	ft_putstr_fd(*str, 1);
	free(*str);
	return (ft_max(flags->width, len));
}

int	unsigned_precision(char **str, t_specif *flags, int len)
{
	if (flags->precision == 0 && *str[0] == '0')
	{
		free(*str);
		return (0);
	}
	print_pad(flags->precision - len, '0');
	ft_putstr_fd(*str, 1);
	free(*str);
	return (ft_max(flags->precision, len));
}

int	print_unsigned(va_list args, t_specif *flags, int *j)
{
	char	*str;
	int		len;

	(*j)++;
	str = ft_itoa_unsign(va_arg(args, unsigned int));
	len = ft_strlen(str);
	if (flags->width > flags->precision && flags->width >= len)
	{
		if (flags->precision == 0 && str[0] == '0')
		{
			free(str);
			return (print_pad(flags->width, ' '));
		}
		if (flags->pad_moins == 1)
			return (unsigned_left(&str, flags, len));
		else
			return (unsigned_noleft(&str, flags, len));
	}
	else
		return (unsigned_precision(&str, flags, len));
	return (0);
}
