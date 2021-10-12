/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:16:08 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/07 12:56:25 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t need_len;

	if (*needle == '\0' || !needle)
		return ((char *)haystack);
	need_len = ft_strlen(needle);
	if (!haystack && n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (ft_strncmp(&haystack[i], needle, need_len) == 0)
		{
			if (i + need_len > n)
				return (0);
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
