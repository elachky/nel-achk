/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:50:28 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 17:07:24 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	test_width(char *fmt, t_specif *flags, va_list args, int *j)
{
	while (fmt[*j] == ' ')
		(*j)++;
	if (ft_isdigit(fmt[*j]))
	{
		flags->width = 0;
		while (ft_isdigit(fmt[*j]))
			flags->width = flags->width * 10 + fmt[(*j)++] - '0';
	}
	else if (fmt[*j] == '*')
	{
		flags->width = va_arg(args, int);
		flags->pad_moins = flags->width < 0 ? 1 : flags->pad_moins;
		flags->width = flags->width < 0 ? -flags->width : flags->width;
		(*j)++;
	}
}
