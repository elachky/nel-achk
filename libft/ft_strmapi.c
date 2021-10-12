/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:24:58 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/09 21:18:35 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;
	int		c;

	c = -1;
	if (!s || !f)
		return (0);
	i = ft_strlen((char *)s);
	if (!(p = malloc(i + 1)))
		return (0);
	while (++c < i)
		p[c] = f((unsigned int)c, s[c]);
	p[c] = '\0';
	return (p);
}
