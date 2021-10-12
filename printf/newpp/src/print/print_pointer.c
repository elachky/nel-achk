/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:35:55 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/23 13:40:36 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ptr_left(char **str, t_specif *flags, int len)
{
	int i;

	i = ft_max(len, flags->precision);
	ft_putstr_fd("0x", 1);
	print_pad(flags->precision - len, '0');
	ft_putstr_fd(*str, 1);
	print_pad(flags->width - i, ' ');
	free(*str);
	return (ft_max(flags->width, i));
}

int	ptr_noleft(char **str, t_specif *flags, int len)
{
	if (flags->pad_zero == 1 && flags->precision < 0)
	{
		ft_putstr_fd("0x", 1);
		print_pad(flags->width - len, '0');
	}
	else
	{
		print_pad(flags->width - ft_max(flags->precision, len), ' ');
		ft_putstr_fd("0x", 1);
		print_pad(flags->precision - len, '0');
	}
	ft_putstr_fd(*str, 1);
	free(*str);
	return (ft_max(flags->width, len));
}

int	ptr_precision(char **str, t_specif *flags, int len)
{
	ft_putstr_fd("0x", 1);
	if (flags->precision == 0 && **str == '0')
		return (2);
	print_pad(flags->precision - 2, '0');
	ft_putstr_fd(*str, 1);
	free(*str);
	return (ft_max(flags->precision, len));
}

int	ptr_null(t_specif *flags)
{
	int i;

	i = print_pad(flags->width - 2, ' ') + 2;
	ft_putstr_fd("0x", 1);
	return (i);
}

int	print_pointer(va_list args, t_specif *flags, int *j)
{
	char	*str;
	int		len;

	(*j)++;
	str = ft_itoa_hexa(va_arg(args, long unsigned int));
	len = ft_strlen(str) + 2;
	if (flags->width > flags->precision && flags->width >= len)
	{
		if (flags->precision == 0 && str[0] == '0')
		{
			free(str);
			return (ptr_null(flags));
		}
		if (flags->pad_moins == 1)
			return (ptr_left(&str, flags, len));
		else
			return (ptr_noleft(&str, flags, len));
	}
	else
		return (ptr_precision(&str, flags, len));
	return (0);
}
