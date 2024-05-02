/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:49:50 by omartela          #+#    #+#             */
/*   Updated: 2024/05/02 15:49:33 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nitems == 0 || size == 0)
		return (ft_calloc(1, 1));
	total = size * nitems;
	if (size > 0 && nitems > 0 && size != (total / nitems))
		return (NULL);
	ptr = (void *)malloc(nitems * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

