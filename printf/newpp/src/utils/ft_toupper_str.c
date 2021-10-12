/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:59:41 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/21 22:23:24 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_toupper_str(char *str)
{
	int		i;
	char	*ptr;

	i = ft_strlen(str);
	ptr = malloc(i + 1);
	ptr[i] = '\0';
	while (i >= 0)
	{
		i--;
		ptr[i] = ft_toupper(str[i]);
	}
	free(str);
	return (ptr);
}
