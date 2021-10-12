/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:52:49 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/12 18:59:31 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static int	ft_len(unsigned int n)
{
	unsigned int	tmp;
	int				size;

	tmp = n;
	size = 0;
	while (tmp > 0)
	{
		size++;
		tmp = tmp / 10;
	}
	return (size);
}

char		*ft_itoa_unsign(unsigned int n)
{
	char	*ptr;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_len(n);
	if (!(ptr = (char*)malloc(size + 1)))
		return (0);
	ptr[size] = '\0';
	while (n > 0 && size >= 0)
	{
		ptr[--size] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}
