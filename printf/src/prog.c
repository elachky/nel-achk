/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:54:23 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/11 10:27:20 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	flags_init(t_specif *flags)
{
	flags->pad_zero = 0;
	flags->pad_moins = 0;
	flags->width = -1;
	flags->precision = -1;
	flags->min_width = 0;
}

char	*get_arg(char c, va_list args)
{
	if (c == 'p')
		return (ft_itoa_hexa(va_arg(args, long unsigned int)));
	return (ft_itoa_hexa(va_arg(args, unsigned int)));
}

int		print_arg(char *fmt, t_specif *flags, va_list args, int *j)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_isalpha(fmt[*j]))
	{
		if (fmt[*j] == 'd' || fmt[*j] == 'i' || fmt[*j] == 'u')
		{
			i = print_int(&str, flags, args, fmt[(*j)++]);
			free(str);
		}
		else if (fmt[*j] == 'c')
			i = print_char(va_arg(args, int), flags, j);
		else if (fmt[*j] == 's')
			i = print_str(&str, flags, args, j);
		else if (fmt[*j] == 'x' || fmt[*j] == 'X' || fmt[*j] == 'p')
		{
			str = get_arg(fmt[*j], args);
			i = print_hexa(&str, flags, fmt[(*j)++]);
			free(str);
		}
	}
	else if (fmt[*j] == '%')
		i = print_prst(flags, j);
	return (i);
}

int		prog(char *fmt, va_list args)
{
	int			i;
	int			j;
	t_specif	flags;

	i = 0;
	j = 0;
	flags_init(&flags);
	while (fmt[j] != '\0')
	{
		if (fmt[j] == '%')
		{
			j++;
			test_pad(fmt, &flags, &j);
			test_width(fmt, &flags, args, &j);
			test_precision(fmt, &flags, args, &j);
			i += print_arg(fmt, &flags, args, &j);
			flags_init(&flags);
		}
		else
		{
			ft_putchar_fd(fmt[j++], 1);
			i++;
		}
	}
	return (i);
}
