/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:55:48 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 03:42:00 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char			*ft_itoa(int n)
{
	char	*ptr;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_size(n);
	if (!(ptr = (char*)ft_calloc(size + 2, 1)))
		return (NULL);
	if (n == -2147483648)
	{
		ptr[0] = '-';
		ptr[1] = '2';
		n = 147483648;
	}
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
