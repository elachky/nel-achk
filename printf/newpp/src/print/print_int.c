/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:21:30 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 17:29:47 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	check_sign(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	return (num);
}

int	int_left(t_specif *flags, int num)
{
	int len;

	len = ft_size(num);
	(num < 0) ? flags->precision++ : 0;
	num = check_sign(num);
	print_pad(flags->precision - len, '0');
	ft_putnbr(num);
	print_pad(flags->width - ft_max(flags->precision, len), ' ');
	return (ft_max(flags->width, len));
}

int	int_noleft(t_specif *flags, int num, int len)
{
	if (flags->pad_zero == 1 && flags->precision < 0)
	{
		(num < 0) ? flags->precision++ : 0;
		num = check_sign(num);
		print_pad(flags->width - len, '0');
	}
	else
	{
		(num < 0) ? flags->precision++ : 0;
		print_pad(flags->width - ft_max(flags->precision, len), ' ');
		num = check_sign(num);
		print_pad(flags->precision - len, '0');
	}
	ft_putnbr(num);
	return (ft_max(flags->width, len));
}

int	print_precision(t_specif *flags, int num, int len)
{
	if (flags->precision == 0 && num == 0)
		return (0);
	(num < 0) ? flags->precision++ : 0;
	num = check_sign(num);
	print_pad(flags->precision - len, '0');
	ft_putnbr(num);
	return (ft_max(flags->precision, len));
}

int	print_int(va_list args, t_specif *flags, int *j)
{
	int num;
	int len;

	(*j)++;
	num = va_arg(args, int);
	len = ft_size(num);
	if (flags->width > flags->precision && flags->width >= len)
	{
		if (flags->precision == 0 && num == 0)
			return (print_pad(flags->width, ' '));
		if (flags->pad_moins == 1)
			return (int_left(flags, num));
		else
			return (int_noleft(flags, num, len));
	}
	else
		return (print_precision(flags, num, len));
	return (0);
}
