/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:10:02 by nel-achk          #+#    #+#             */
/*   Updated: 2019/11/08 15:08:44 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;

	if (!f || !del || !lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	list = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (list);
}
