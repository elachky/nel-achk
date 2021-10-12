/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:15:46 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/10 20:09:10 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int	print_prst(t_specif *flags, int *j)
{
	if (flags->pad_moins == 1)
	{
		put('%', 1);
		put(' ', flags->width - 1);
	}
	else if (flags->pad_zero == 1)
	{
		put('0', flags->width - 1);
		put('%', 1);
	}
	else
	{
		put(' ', flags->width - 1);
		put('%', 1);
	}
	(*j)++;
	return (ft_max(1, flags->width));
}
