/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:31:36 by omartela          #+#    #+#             */
/*   Updated: 2024/04/16 15:38:49 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

#include <stdio.h>

void test_ft_isalpha() {
    // Test cases for lowercase letters
    printf("Test cases for lowercase letters:\n");
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isalpha('a')); // should return 1
    printf("Actual Output: %d\n", ft_isalpha('z')); // should return 1

    // Test cases for uppercase letters
    printf("\nTest cases for uppercase letters:\n");
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isalpha('A')); // should return 1
    printf("Actual Output: %d\n", ft_isalpha('Z')); // should return 1

    // Test cases for non-alphabetic characters
    printf("\nTest cases for non-alphabetic characters:\n");
    printf("Expected Output: 0\n");
    printf("Actual Output: %d\n", ft_isalpha('0')); // should return 0
    printf("Actual Output: %d\n", ft_isalpha('&')); // should return 0
}

int main() {
    test_ft_isalpha();
    return 0;
}