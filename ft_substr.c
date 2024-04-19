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

int main()
{
	char const src[19] = "Hello Hive";
	char const src1[7] = "";
	char *result1, *result3, *result5, *result7, *result8;
	char *result2, *result4, *result6;

	result1 = ft_substr(src, 3, 3);
	printf("The substring is: %s\n", result1);
	result2 = ft_substr(src, 3, 0);
	printf("The substring is: %s\n", result2);
	result3 = ft_substr(src, 3, 1);
	printf("The substring is: %s\n", result3);
	result4 = ft_substr(src, 3, 20);
	printf("The substring is: %s\n", result4);
	result5 = ft_substr(src, 0, 3);
	printf("The substring is: %s\n", result5);
	result6 = ft_substr(src, 20, 3);
	printf("The substring is: %s\n", result6);
	result7 = ft_substr(src1, 3, 3);
	printf("The substring is: %s\n", result7);
	result8 = ft_substr(src1, 0, 0);
	printf("The substring is: %s\n", result8);
	return 0;
}