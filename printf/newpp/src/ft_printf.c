/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:38:29 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 17:59:02 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	flags_init(t_specif *flags)
{
	flags->pad_zero = 0;
	flags->pad_moins = 0;
	flags->width = -2;
	flags->precision = -2;
	flags->str_null = 0;
}

int		print_specifier(char *fmt, t_specif *flags, va_list args, int *j)
{
	if (fmt[*j] == 'd' || fmt[*j] == 'i')
		return (print_int(args, flags, j));
	else if (fmt[*j] == 'x' || fmt[*j] == 'X')
		return (print_hexa(args, flags, j, fmt[*j]));
	else if (fmt[*j] == 'p')
		return (print_pointer(args, flags, j));
	else if (fmt[*j] == 'u')
		return (print_unsigned(args, flags, j));
	else if (fmt[*j] == 's')
		return (print_str(args, flags, j));
	else if (fmt[*j] == 'c')
		return (print_char((char)va_arg(args, int), flags, j));
	else if (fmt[*j] == '%')
		return (print_char('%', flags, j));
	return (0);
}

int		print_arg(char *fmt, t_specif *flags, va_list args, int *j)
{
	int i;

	i = 0;
	(*j)++;
	test_pad(fmt, flags, j);
	test_width(fmt, flags, args, j);
	test_precision(fmt, flags, args, j);
	i = print_specifier(fmt, flags, args, j);
	flags_init(flags);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			j;
	t_specif	flags;
	char		*fmt;

	i = 0;
	j = 0;
	fmt = (char*)format;
	if (fmt == NULL)
		return (0);
	va_start(args, format);
	flags_init(&flags);
	while (fmt[j] != '\0')
	{
		if (fmt[j] == '%')
			i += print_arg(fmt, &flags, args, &j);
		else
			i += write(1, &fmt[j++], 1);
	}
	va_end(args);
	return (i);
}
