/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:00:52 by omartela          #+#    #+#             */
/*   Updated: 2024/04/23 09:00:52 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->next = 0;
	node->content = malloc(sizeof(*content));
	if (!node->content)
	{
		free(node);
		return (0);
	}
	ft_memcpy(node->content, content, sizeof(content));
	return (node);
}
