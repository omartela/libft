/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:00 by omartela          #+#    #+#             */
/*   Updated: 2024/04/16 16:50:33 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

#include <stdio.h>

void test_ft_isprint() {
    printf("Test cases for ft_isprint:\n");
    
    // Test cases for printable characters
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isprint(32)); // should return 1 (space)
    printf("Actual Output: %d\n", ft_isprint(65)); // should return 1 ('A')
    printf("Actual Output: %d\n", ft_isprint(126)); // should return 1 ('~')

    // Test cases for non-printable characters
    printf("Expected Output: 0\n");
    printf("Actual Output: %d\n", ft_isprint(31)); // should return 0 (non-printable)
    printf("Actual Output: %d\n", ft_isprint(127)); // should return 0 (non-printable)
    printf("Actual Output: %d\n", ft_isprint(0)); // should return 0 (null character)
}

int main() {
    test_ft_isprint();
    return 0;
}