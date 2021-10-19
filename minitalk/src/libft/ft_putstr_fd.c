/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:23:19 by nel-achk          #+#    #+#             */
/*   Updated: 2021/10/19 15:23:20 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

size_t	ft_putstr_fd(int fd, const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		ft_putchar_fd(fd, str[i++]);
	return (i);
}
