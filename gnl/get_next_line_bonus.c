/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:10:06 by nel-achk          #+#    #+#             */
/*   Updated: 2020/01/17 18:11:58 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*reads[MAX_FD];
	int			i;

	if (fd < 0 || line == NULL || read(fd, reads[fd], 0) == -1)
		return (-1);
	*line = malloc(1);
	**line = '\0';
	while (1)
	{
		if (!(reads[fd] && *reads[fd]))
			if ((reads[fd] = read_buff(fd, &reads[fd])) == NULL)
				return (0);
		if ((i = check_line(reads[fd])) == -1)
		{
			*line = ft_strjoin(*line, reads[fd]);
			reads[fd] = ft_strdup("\0");
		}
		else
		{
			*line = ft_strjoin(*line, ft_substr(ft_strdup(reads[fd]), 0, i));
			reads[fd] = ft_substr(reads[fd], i + 1, ft_strlen(reads[fd]) - i);
			return (1);
		}
	}
}
