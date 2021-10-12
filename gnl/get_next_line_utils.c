/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:17:41 by nel-achk          #+#    #+#             */
/*   Updated: 2020/01/18 16:25:19 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;
	size_t			len_s;

	i = 0;
	len_s = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!ptr)
		return (NULL);
	while (start < len_s && i < len && s[start] != '\0')
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	free(s);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
		p[k++] = s1[i++];
	while (s2[j])
		p[k++] = s2[j++];
	p[k] = '\0';
	free(s1);
	free(s2);
	return (p);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*p;

	i = -1;
	if (!(p = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		p[i] = s[i];
	p[i] = '\0';
	return (p);
}
