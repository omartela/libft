/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:49:50 by omartela          #+#    #+#             */
/*   Updated: 2024/04/29 16:54:17 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (size > 0 && nitems > 0 && size > (SIZE_MAX / nitems))
		return (NULL);
	ptr = (void *)malloc(nitems * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
