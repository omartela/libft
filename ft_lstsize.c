/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:48:00 by omartela          #+#    #+#             */
/*   Updated: 2024/04/23 10:53:15 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n_nodes;

	if (!lst)
		return (0);
	n_nodes = 0;
	while (lst != 0)
	{
		lst = lst->next;
		n_nodes = n_nodes + 1;
	}
	return (n_nodes);
}

/* int main(void)
{
	t_list	*l;

	l = ft_lstnew(ft_strdup("1"));
 	l->next = ft_lstnew(ft_strdup("2"));
 	l->next->next = ft_lstnew(ft_strdup("3"));
	printf("%d", ft_lstsize(l));
} */