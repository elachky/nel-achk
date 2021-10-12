/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:58:36 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/09 15:56:29 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *str, char c)
{
	int nbr;
	int i;

	nbr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0' &&
				(str[i + 1] == c || str[i + 1] == '\0'))
		{
			i++;
			nbr++;
		}
		if (str[i] == '\0')
			return (nbr);
		i++;
	}
	return (nbr);
}

static char	**ft_free_memory(char **p, int n)
{
	int i;

	i = 0;
	if (p)
	{
		while (i < n)
			free(p[i++]);
		free(p);
	}
	return (NULL);
}

static int	ft_size(char const *str, int k, char c)
{
	int i;

	i = 0;
	while (str[k] != c && str[k] != '\0')
	{
		i++;
		k++;
	}
	return (i);
}

char		**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**p;

	i = 0;
	k = 0;
	if (!str || !(p = malloc((ft_words(str, c) + 1) * sizeof(char*))))
		return (NULL);
	while (str[k])
	{
		while (str[k] == c && str[k])
			k++;
		if (str[k])
		{
			j = 0;
			if (!(p[i] = malloc(sizeof(char) * (ft_size(str, k, c) + 1))))
				return (ft_free_memory(p, i));
			while (str[k] != c && str[k])
				p[i][j++] = str[k++];
			p[i++][j] = '\0';
		}
	}
	p[i] = NULL;
	return (p);
}
