/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:18:38 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/09 15:39:01 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			lens;
	unsigned int	j;

	j = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] != '\0' && j < len && start < lens)
		p[j++] = s[start++];
	p[j] = '\0';
	return (p);
}
