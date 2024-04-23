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

t_list *ft_lstnew(void *content)
{
    t_list *ptr;
    ptr = malloc(sizeof(t_list));
    if (!ptr)
        return (0);
    ptr[0].next = NULL;
    ptr[0].content = malloc(sizeof(*content));
    if (!ptr[0].content)
        return (0);
}