/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:18:17 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/21 22:22:37 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	*ft_calloc(size_t count, size_t size)
{
	char *p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(p = malloc(count * size)))
		return (0);
	ft_bzero(p, count * size);
	return ((void *)p);
}
