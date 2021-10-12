/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:25:03 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/22 03:27:46 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		len_n(long unsigned int n)
{
	int size;

	size = 0;
	while (n > 0)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

char	*ft_itoa_hexa(long unsigned int n)
{
	char	*base;
	char	*str;
	int		i;

	i = len_n(n);
	base = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (n > 0)
	{
		str[--i] = base[n % 16];
		n /= 16;
	}
	return (str);
}
