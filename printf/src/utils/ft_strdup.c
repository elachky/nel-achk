/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:14:50 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/12 19:06:54 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	if (!s1)
		return (NULL);
	i = ft_strlen((char *)s1);
	if (!(p = malloc(i + 1)))
		return (NULL);
	p[i] = '\0';
	while (i--)
		p[i] = (char)s1[i];
	return (p);
}
