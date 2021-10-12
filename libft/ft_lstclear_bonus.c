/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:52:13 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/08 12:18:39 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		free(*lst);
		*lst = (*lst)->next;
	}
	free(*lst);
}
