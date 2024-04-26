/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:49:50 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 12:57:08 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	*ptr;
	size_t	total_m;

	total_m = nitems * size;
	if (total_m / nitems != size)
		return (NULL);
	ptr = (void *)malloc(total_m);
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, total_m);
	return (ptr);
}
