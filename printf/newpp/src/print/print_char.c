/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:17:53 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 17:18:08 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_char(char c, t_specif *flags, int *j)
{
	if (flags->pad_moins == 1)
	{
		put(c, 1);
		put(' ', flags->width - 1);
	}
	else if (flags->pad_zero == 1)
	{
		put('0', flags->width - 1);
		put(c, 1);
	}
	else
	{
		put(' ', flags->width - 1);
		put(c, 1);
	}
	(*j)++;
	return (ft_max(1, flags->width));
}
