/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsi <rsi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:35:21 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/03 17:19:13 by rsi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf(const char *fmt, ...)
{
	int		printed;
	va_list	args;

	if (fmt == NULL)
		return (0);
	va_start(args, fmt);
	printed = prog((char *)fmt, args);
	va_end(args);
	return (printed);
}
