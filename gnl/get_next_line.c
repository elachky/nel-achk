/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:07:46 by nel-achk          #+#    #+#             */
/*   Updated: 2020/01/17 18:10:47 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_line(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_buff(int fd, char **reads)
{
	char	*buffer;
	int		i;

	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (NULL);
	if ((i = read(fd, buffer, BUFFER_SIZE)) == 0)
	{
		free(*reads);
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	free(*reads);
	*reads = ft_strjoin(ft_strdup(""), buffer);
	return (*reads);
}

int		get_next_line(int fd, char **line)
{
	static char	*reads;
	int			i;

	if (fd < 0 || line == NULL || read(fd, reads, 0) == -1)
		return (-1);
	*line = malloc(1);
	**line = '\0';
	while (1)
	{
		if (!(reads && *reads))
			if ((reads = read_buff(fd, &reads)) == NULL)
				return (0);
		if ((i = check_line(reads)) == -1)
		{
			*line = ft_strjoin(*line, reads);
			reads = ft_strdup("\0");
		}
		else
		{
			*line = ft_strjoin(*line, ft_substr(ft_strdup(reads), 0, i));
			reads = ft_substr(reads, i + 1, ft_strlen(reads) - i + 1);
			return (1);
		}
	}
}
