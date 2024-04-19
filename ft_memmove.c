/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:57:07 by omartela          #+#    #+#             */
/*   Updated: 2024/04/17 18:40:16 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;

	if (!dst && !src)
		return (0);

	if (dst <= src)
		ft_memcpy(dest, source, len);
	else
	{
		dest += len - 1;
		source += len - 1;
		while (len > 0)
		{
			*dest-- = *source--;
			len = len - 1;
		}
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>

// Test function
void test_memmove() {
    // Test case 1: Moving from src to dst
    char str1[] = "1234567890";
    char str2[20] = "abcdefghij";
	char str20[] = "1234567890";
    char str22[20] = "abcdefghij";
    ft_memmove(str2 + 3, str1 + 2, 5);
	printf("Test Case 1: %s\n", str2);
	memmove(str22 + 3, str20 + 2, 5);
    printf("Test Case 1: %s\n", str22);

    // Test case 2: Moving from dst to src
    char str3[] = "1234567890";
    ft_memmove(str3 + 2, str3 + 4, 5);
    printf("Test Case 2: %s\n", str3);

    // Test case 3: Moving overlapping memory region forward
    char str4[] = "1234567890";
	// void *ft_memmove(void *dst, const void *src, size_t len)
    ft_memmove(str4 + 4, str4 + 2, 4);
    printf("Test Case 3: %s\n", str4);

    // Test case 4: Moving overlapping memory region backward
    char str5[] = "1234567890";
    ft_memmove(str5 + 2, str5 + 4, 4);
    printf("Test Case 4: %s\n", str5);

    // Test case 5: Moving non-overlapping memory region
    char str6[] = "1234567890";
    ft_memmove(str6 + 10, str6, 3);
    printf("Test Case 5: %s\n", str6); // Output should be: "1234567890123"

    // Test case 6: Moving non-overlapping memory region (dst < src)
    char str7[] = "1234567890";
    ft_memmove(str7, str7 + 2, 5);
    printf("Test Case 6: %s\n", str7); // Output should be: "3456787890"

    // Test case 7: Moving non-overlapping memory region (dst > src)
    char str8[] = "1234567890";
    ft_memmove(str8 + 2, str8, 5);
    printf("Test Case 7: %s\n", str8); // Output should be: "121234567890"
}

int main() {
    // Run tests
    test_memmove();
    return 0;
}