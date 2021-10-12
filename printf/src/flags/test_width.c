/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:50:28 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/10 17:25:53 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	test_width(char *fmt, t_specif *flags, va_list args, int *j)
{
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
