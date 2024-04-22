/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:41:57 by omartela          #+#    #+#             */
/*   Updated: 2024/04/17 08:56:34 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
	{
		if (c == *ptr)
		{
			return (ptr);
		}
		++ptr;
	}
	if (c == *ptr)
	{
		return (ptr);
	}
	return (0);
}
