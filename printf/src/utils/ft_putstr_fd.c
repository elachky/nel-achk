/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:36:08 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/12 19:04:54 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
}
