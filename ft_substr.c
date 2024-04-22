/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:06:00 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 15:17:29 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;
	char		*rptr;
	size_t		sublen;

	i = 0;
	if (!s)
		return (0);
	sublen = ft_strlen(s);
	if (start + 1 > sublen)
		return (0);
	if (len < sublen)
		sublen = len;
	ptr = malloc(sizeof(char) * sublen + 1);
	if (!ptr)
		return (0);
	rptr = ptr;
	while (i < sublen && s)
	{
		*ptr = s[start];
		start++;
		i++;
		++ptr;
	}
	ptr[i] = '\0';
	return (rptr);
}
