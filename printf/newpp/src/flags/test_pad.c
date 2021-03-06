/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:48:02 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/21 22:33:46 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
