/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:34:53 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 17:35:13 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	str_width(t_specif *flags, char *str, int len)
{
	if (flags->pad_moins == 1)
	{
		write(1, str, len);
		print_pad(flags->width - len, ' ');
	}
	else if (flags->pad_zero == 1)
	{
		print_pad(flags->width - len, '0');
		write(1, str, len);
	}
	else
	{
		print_pad(flags->width - len, ' ');
		write(1, str, len);
	}
}

int		print_str(va_list args, t_specif *flags, int *j)
{
	char	*str;
	int		i;

	(*j)++;
	if (flags->precision == 0)
		return (put(' ', flags->width));
	str = va_arg(args, char*);
	if (!str && (str = ft_strdup("(null)")))
		flags->str_null = 1;
	i = ft_strlen(str);
	if (flags->precision > -1)
		i = flags->precision < i ? flags->precision : i;
	if (flags->width > 0)
		str_width(flags, str, i);
	else
		write(1, str, i);
	if (flags->str_null == 1)
		free(str);
	return (ft_max(i, flags->width));
}
