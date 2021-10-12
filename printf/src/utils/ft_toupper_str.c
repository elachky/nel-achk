/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:59:41 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:10 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char	*ft_toupper_str(char *str)
{
	int		i;
	char	*ptr;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	while (i >= 0)
	{
		i--;
		ptr[i] = ft_toupper(str[i]);
	}
	free(str);
	return (ptr);
}
