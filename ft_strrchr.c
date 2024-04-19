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

/* #include <stdio.h>
#include <string.h>
int main () 
{
	const char str[] = "Hello.Hive.Five";
	const char ch = '.';
	const char ch2 = 'D';
	const char ch3 = '\0';
	char *result, *result2, *result3;
	char *result4, *result5, *result6;

	result = strrchr(str, ch);
	result2 = ft_strrchr(str, ch);

	printf("String after orig |%c| is - |%s|\n", ch, result);
	printf("String after mine |%c| is - |%s|\n", ch, result2);

	result3 = strrchr(str, ch2);
	result4 = ft_strrchr(str, ch2);

	printf("String after orig |%c| is - |%s|\n", ch2, result3);
	printf("String after mine |%c| is - |%s|\n", ch2, result4);

	result5 = strrchr(str, ch3);
	result6 = ft_strrchr(str, ch3);

	printf("String after orig |%c| is - |%s|\n", ch3, result5);
	printf("String after mine |%c| is - |%s|\n", ch3, result6);
	
	return(0);
} */