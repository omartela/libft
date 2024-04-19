/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:50 by omartela          #+#    #+#             */
/*   Updated: 2024/01/22 18:04:56 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < (n - 1))
		i++;
	if ((n == 0) || (s1[i] == s2[i]))
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char str1[] = "Hella";
    char str2[] = "Hello";
    unsigned int n1 = 5;

    char str3[] = "Hello";
    char str4[] = "World";
    unsigned int n2 = 3;

    char str5[] = "Apples";
    char str6[] = "Bananas";
    unsigned int n3 = 7;

    printf("Test 1 (ft_strncmp): %d\n", ft_strncmp(str1, str2, n1));
    printf("Test 1 (strncmp): %d\n", strncmp(str1, str2, n1));

    printf("Test 2 (ft_strncmp): %d\n", ft_strncmp(str3, str4, n2));
    printf("Test 2 (strncmp): %d\n", strncmp(str3, str4, n2));

    printf("Test 3 (ft_strncmp): %d\n", ft_strncmp(str5, str6, n3));
    printf("Test 3 (strncmp): %d\n", strncmp(str5, str6, n3));

    return 0;
}
*/
