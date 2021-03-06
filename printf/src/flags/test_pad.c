/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsi <rsi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:48:02 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/03 17:21:20 by rsi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	test_pad(char *fmt, t_specif *flags, int *j)
{
	while ((fmt[*j] == '0' || fmt[*j] == '-') && fmt[*j] != '\0')
	{
		if (fmt[*j] == '0')
			flags->pad_zero = 1;
		if (fmt[*j] == '-')
			flags->pad_moins = 1;
		(*j)++;
	}
}
