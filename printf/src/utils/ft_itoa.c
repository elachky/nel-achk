/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:55:48 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/12 18:43:22 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static int		ft_size(int n)
{
	long	tmp;
	int		size;

	tmp = n;
	size = 0;
	if (tmp < 0)
		tmp = -tmp;
	while (tmp > 0)
	{
		size++;
		tmp = tmp / 10;
	}
	if (n <= 0)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(n);
	ptr = (char*)ft_calloc(size + 1, 1);
	if (ptr == NULL)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n > 0 && size >= 0)
	{
		ptr[--size] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}
