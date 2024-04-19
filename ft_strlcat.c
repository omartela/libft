/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:31:32 by omartela          #+#    #+#             */
/*   Updated: 2024/01/18 16:34:55 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i = i + 1;
	}
	while (src[j] != '\0' && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j = j + 1;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char dest1[20] = "Hello";
    char src1[] = "World";
    unsigned int size1 = sizeof(dest1);

    char dest2[20] = "Hello";
    char src2[] = "World";
    unsigned int size2 = sizeof(dest2);

    char dest3[10] = "Hello";
    char src3[] = "World";
    unsigned int size3 = sizeof(dest3);

	char dest4[10] = "Hello";
	char src4[] = "World";
	unsigned int size4 = sizeof(dest4);

    printf("Test 1 (ft_strlcat): %u\n", ft_strlcat(dest1, src1, size1));
    printf("Test 1 (strlcat): %lu\n", strlcat(dest2, src2, size2));

    printf("Test 2 (ft_strlcat): %u\n", ft_strlcat(dest3, src3, size3));
    printf("Test 2 (strlcat): %lu\n", strlcat(dest4, src4, size4));

    printf("Modified dest1: %s\n", dest1);
    printf("Modified dest2: %s\n", dest2);
    printf("Modified dest3: %s\n", dest3);
	printf("Modified dest4: %s\n", dest4);

    return 0;
}*/
