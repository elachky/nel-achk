/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:18:06 by fmehdaou          #+#    #+#             */
/*   Updated: 2019/11/10 14:26:17 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(long int n)
{
	long int	tmp;
	long int	size;

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
	char		*ptr;
	long int	size;
	long int	nn;
	long int	test;

	size = 0;
	nn = (long int)n;
	size = ft_size(n);
	ptr = (char*)malloc(size + 1);
	if (!ptr)
		return (ptr);
	ptr[size] = '\0';
	if (nn == 0)
		ptr[--size] = '0';
	test = nn;
	if (nn < 0)
		nn = -nn;
	while (nn > 0 && size >= 0)
	{
		ptr[--size] = nn % 10 + '0';
		nn = nn / 10;
	}
	if (test < 0)
		ptr[0] = '-';
	return (ptr);
}
