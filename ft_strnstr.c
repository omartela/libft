/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:10:06 by omartela          #+#    #+#             */
/*   Updated: 2024/01/22 18:10:10 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_needle;

	i = 0;
	len_needle = ft_strlen(to_find);
	if (!str)
		len = *str;
	if (len < len_needle)
		return (0);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] == to_find[j] && str[i] && i < len)
		{
			++i;
			++j;
		}
		if (!to_find[j])
			return ((char *)&str[i - j]);
		i = (i - j) + 1;
	}
	return (0);
}
