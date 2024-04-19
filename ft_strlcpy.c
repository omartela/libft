/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:39:17 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 14:05:53 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;

	if (dstsize > 0)
	{
		while (counter < dstsize - 1 && *(src + counter) != '\0')
		{
			*(dst + counter) = *(src + counter);
			counter++;
		}
		*(dst + counter) = '\0';
	}
	return (ft_strlen(src));
}


/* #include <stdio.h>
#include <string.h>
int main()
{
    // Test cases for ft_strlcpy
    char dest[20];
    const char *src = "Hello, world!";
    size_t result;

    // Test case 1: Small buffer
    result = ft_strlcpy(dest, src, 5);
    printf("ft_strlcpy result: %zu, dst: '%s'\n", result, dest);

    // Test case 2: Large buffer
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("ft_strlcpy result: %zu, dst: '%s'\n", result, dest);

    // Test case 3: Empty source string
    const char *empty_src = "";
    result = ft_strlcpy(dest, empty_src, sizeof(dest));
    printf("ft_strlcpy result: %zu, dst: '%s'\n", result, dest);

    // Function calls for original strlcpy for comparison
    char dest2[20];

    // Test case 1: Small buffer
    result = strlcpy(dest2, src, 5);
    printf("strlcpy result: %zu, dst: '%s'\n", result, dest2);

    // Test case 2: Large buffer
    result = strlcpy(dest2, src, sizeof(dest2));
    printf("strlcpy result: %zu, dst: '%s'\n", result, dest2);

    // Test case 3: Empty source string
    result = strlcpy(dest2, empty_src, sizeof(dest2));
    printf("strlcpy result: %zu, dst: '%s'\n", result, dest2);

    return 0;
} */