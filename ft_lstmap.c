/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:10:22 by omartela          #+#    #+#             */
/*   Updated: 2024/04/23 12:22:42 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_node;
	t_list	*c_node;
	t_list	*p_node;
	t_list	*n_node;

	f_node = lst;
	p_node = NULL;
	if (!lst)
		return (0);
	while (lst->next)
	{
		if ((*f)(lst->content) != 0)
		{
			c_node = ft_lstnew((*f)(lst->content));
			if (c_node == 0)
				ft_lstclear(f_node, del);
			n_node = lst->next;
			ft_lstdelone(lst, del);
			lst = n_node;
		}
		else
			lst = lst->next;
		if (p_node != NULL)
			p_node->next = c_node;
		p_node = c_node;
	}
	return (f_node);
}
