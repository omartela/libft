/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:13:10 by omartela          #+#    #+#             */
/*   Updated: 2024/04/17 10:19:37 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		found;

	found = 0;
	ptr = 0;
	while (*str != '\0')
	{
		if (c == *str)
		{
			ptr = (char *)str;
			found = 1;
		}
		++str;
	}
	if (found == 1)
	{
		return (ptr);
	}
	if (c == *str)
	{
		ptr = (char *)str;
		return (ptr);
	}
	return (0);
}
