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

char	*ft_strnstr(const char *str, const char *to_find ,size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_needle;

	i = 0;
	len_needle = ft_strlen(to_find);
	if (len < len_needle)
		return (0);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i])
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

int main () {
	char haystack[20] = "Hello.Hive.Five";
	char haystack2[20] = "\0";
	char needle[10] = "ve";
	char needle2[10] = ".Ha";
	char needle3[10] = "\0";
	size_t len = 10;
	size_t len2 = 1;
	size_t len3 = 0;
	char *result, *result3, *result5, *result7, *result8;
	char *result2, *result4, *result6;

	result = strnstr(haystack, needle, len);
	result2 = ft_strnstr(haystack, needle, len);
	printf("The substring is: %s\n", result);
	printf("The substring is: %s\n\n", result2);

	result = strnstr(haystack, needle, len2);
	result2 = ft_strnstr(haystack, needle, len2);
	printf("The substring is: %s\n", result);
	printf("The substring is: %s\n\n", result2);

	result = strnstr(haystack, needle, len3);
	result2 = ft_strnstr(haystack, needle, len3);
	printf("The substring is: %s\n", result);
	printf("The substring is: %s\n\n", result2);

	result3 = strnstr(haystack, needle2, len);
	result4 = ft_strnstr(haystack, needle2, len);
	printf("The substring is: %s\n", result3);
	printf("The substring is: %s\n\n", result4);

	result3 = strnstr(haystack, needle2, len2);
	result4 = ft_strnstr(haystack, needle2, len2);
	printf("The substring is: %s\n", result3);
	printf("The substring is: %s\n\n", result4);

	result3 = strnstr(haystack, needle2, len3);
	result4 = ft_strnstr(haystack, needle2, len3);
	printf("The substring is: %s\n", result3);
	printf("The substring is: %s\n\n", result4);

	result5 = strnstr(haystack, needle3, len);
	result6 = ft_strnstr(haystack, needle3, len);
	printf("The substring is: %s\n", result5);
	printf("The substring is: %s\n\n", result6);

	result5 = strnstr(haystack, needle3, len2);
	result6 = ft_strnstr(haystack, needle3, len2);
	printf("The substring is: %s\n", result5);
	printf("The substring is: %s\n\n", result6);

	result5 = strnstr(haystack, needle3, len3);
	result6 = ft_strnstr(haystack, needle3, len3);
	printf("The substring is: %s\n", result5);
	printf("The substring is: %s\n\n", result6);

	result7 = strnstr(haystack2, needle, len);
	result8 = ft_strnstr(haystack2, needle, len);
	printf("The substring is: %s\n", result7);
	printf("The substring is: %s\n\n", result8);
	return(0);
}