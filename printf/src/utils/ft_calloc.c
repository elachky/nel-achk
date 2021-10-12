/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:18:17 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/12 18:35:49 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}
