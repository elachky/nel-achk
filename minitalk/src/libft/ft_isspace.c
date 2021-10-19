/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:21:45 by nel-achk          #+#    #+#             */
/*   Updated: 2021/10/19 15:21:46 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_isspace(int c)
{
	unsigned char	i;

	i = (unsigned char)c;
	if (i == ' ')
		return (1);
	if (i == '\n')
		return (1);
	if (i == '\t')
		return (1);
	if (i == '\v')
		return (1);
	if (i == '\r')
		return (1);
	if (i == '\f')
		return (1);
	return (0);
}
