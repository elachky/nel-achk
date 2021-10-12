/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:18:17 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/09 15:06:28 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
