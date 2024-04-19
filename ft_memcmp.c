/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:51:00 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 13:08:55 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*temp_str1;
	unsigned char	*temp_str2;

	temp_str1 = (unsigned char *) str1;
	temp_str2 = (unsigned char *) str2;
	while (n > 0)
	{
		if (*temp_str1 != *temp_str2)
		{
			return (*temp_str1 - *temp_str2);
		}
		n = n - 1;
		temp_str1 = temp_str1 + 1;
		temp_str2 = temp_str2 + 1;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

// Your corrected ft_memcmp implementation

int main() {
    // Test 1: Equal Memory Blocks
    char str1[] = "hello";
    char str2[] = "hello";
    int result1_ft = ft_memcmp(str1, str2, strlen(str1));
    int result1_memcmp = memcmp(str1, str2, strlen(str1));
    printf("Test 1: ft_memcmp result = %d, memcmp result = %d\n", result1_ft, result1_memcmp);

    // Test 2: Different Memory Blocks with Same Size
    char str3[] = "hello";
    char str4[] = "hallo";
    int result2_ft = ft_memcmp(str3, str4, strlen(str3));
    int result2_memcmp = memcmp(str3, str4, strlen(str3));
    printf("Test 2: ft_memcmp result = %d, memcmp result = %d\n", result2_ft, result2_memcmp);

    // Test 3: Different Memory Blocks with Different Sizes
    char str5[] = "hello";
    char str6[] = "hello world";
    int result3_ft = ft_memcmp(str5, str6, strlen(str5));
    int result3_memcmp = memcmp(str5, str6, strlen(str5));
    printf("Test 3: ft_memcmp result = %d, memcmp result = %d\n", result3_ft, result3_memcmp);

    // Add more tests here...

    return 0;
}
