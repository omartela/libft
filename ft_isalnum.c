/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:07:26 by omartela          #+#    #+#             */
/*   Updated: 2024/04/16 16:15:24 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void test_ft_isalnum() {
    printf("Test cases for ft_isalnum:\n");
    
    // Test cases for digits
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isalnum('0')); // should return 1
    printf("Actual Output: %d\n", ft_isalnum('5')); // should return 1
    printf("Actual Output: %d\n", ft_isalnum('9')); // should return 1

    // Test cases for uppercase letters
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isalnum('A')); // should return 1
    printf("Actual Output: %d\n", ft_isalnum('Z')); // should return 1

    // Test cases for lowercase letters
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isalnum('a')); // should return 1
    printf("Actual Output: %d\n", ft_isalnum('z')); // should return 1

    // Test cases for non-alphanumeric characters
    printf("Expected Output: 0\n");
    printf("Actual Output: %d\n", ft_isalnum('*')); // should return 0
    printf("Actual Output: %d\n", ft_isalnum('@')); // should return 0
    printf("Actual Output: %d\n", ft_isalnum('\n')); // should return 0
}

int main() {
    test_ft_isalnum();
    return 0;
}