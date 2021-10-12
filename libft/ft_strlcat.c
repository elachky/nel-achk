/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:02:39 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/09 21:13:54 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	if (!dest && size == 0)
		return (ft_strlen(src));
	j = ft_strlen(dest);
	k = j;
	i = -1;
	if (j >= size)
		return (size + ft_strlen(src));
	while (src[++i] && i < size - k - 1)
		dest[j + i] = src[i];
	dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
