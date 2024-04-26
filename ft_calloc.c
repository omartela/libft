/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:49:50 by omartela          #+#    #+#             */
/*   Updated: 2024/04/26 14:57:02 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	total_m;

	total_m = nitems * size;
	if (size > 0 && nitems > 0 && total_m / nitems != size)
		return (NULL);
	ptr = (void *)malloc(total_m);
	if (!ptr)
		return (0);
	ft_bzero(ptr, total_m);
	return (ptr);
}
