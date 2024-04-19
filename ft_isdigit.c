/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:53:40 by omartela          #+#    #+#             */
/*   Updated: 2024/04/16 15:57:48 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


#include <stdio.h> 
// Function to perform the tests
void test_ft_isdigit() 
{
    // Test cases for digits
    printf("Test cases for digits:\n");
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isdigit('0')); // should return 1
    printf("Actual Output: %d\n", ft_isdigit('5')); // should return 1
    printf("Actual Output: %d\n", ft_isdigit('9')); // should return 1

    // Test cases for non-digits
    printf("\nTest cases for non-digits:\n");
    printf("Expected Output: 0\n");
    printf("Actual Output: %d\n", ft_isdigit('a')); // should return 0
    printf("Actual Output: %d\n", ft_isdigit('@')); // should return 0
}

// Function to test ft_isdigit
int main()
{
    test_ft_isdigit();
    return 0;
}