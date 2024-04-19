/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:34:09 by omartela          #+#    #+#             */
/*   Updated: 2024/04/16 16:38:05 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

#include <stdio.h>

void test_ft_isascii() {
    printf("Test cases for ft_isascii:\n");
    
    // Test cases for valid ASCII characters
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isascii(0)); // should return 1
    printf("Actual Output: %d\n", ft_isascii(65)); // should return 1 ('A')
    printf("Actual Output: %d\n", ft_isascii(127)); // should return 1 (DEL)

    // Test cases for non-ASCII characters
    printf("Expected Output: 0\n");
    printf("Actual Output: %d\n", ft_isascii(-1)); // should return 0
    printf("Actual Output: %d\n", ft_isascii(128)); // should return 0
    printf("Actual Output: %d\n", ft_isascii(255)); // should return 0
}

// Main function to run the tests
int main() {
    test_ft_isascii();
    return 0;
}