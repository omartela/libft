/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:11:20 by omartela          #+#    #+#             */
/*   Updated: 2024/04/19 14:45:17 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_subs_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0' || *s == c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int nsubs;
	int i;
	int subs_index;
	int start;
	int subs_len;
	char **result;

	i = 0;
	while (s[i])
	{
		if (s[i] == c || s[i + 1] == '\0')
			nsubs++;
		i++;
	}
	result = (char **)malloc((nsubs + 1) * sizeof(char *))
	if (!result)
		return (0);
	subs_index = 0;
	start = 0;
	while (*s != '\0')
	{
		subs_len = ft_subs_len(s, c);
		if (s  == c || *(s + 1) == '\0')
		{
			result[subs_index] = ft_substr(*s, start, subs_len);
			subs_index++;
			start = s + 1;
		}
		s++;
	}
	result[nsubs] = 0;
	return (result);
}
