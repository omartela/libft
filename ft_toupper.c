/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:16:41 by omartela          #+#    #+#             */
/*   Updated: 2024/04/17 08:31:53 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}


#include <assert.h>
#include <stdio.h>
int main() {
    // Test cases for lowercase letters
    assert(ft_toupper('a') == 'A');
    assert(ft_toupper('b') == 'B');
    assert(ft_toupper('z') == 'Z');

    // Test cases for uppercase letters
    assert(ft_toupper('A') == 'A');
    assert(ft_toupper('B') == 'B');
    assert(ft_toupper('Z') == 'Z');

    // Test cases for non-alphabetic characters
    assert(ft_toupper('0') == '0');
    assert(ft_toupper('#') == '#');
    assert(ft_toupper(' ') == ' ');

    // Additional test cases
    assert(ft_toupper('c') == 'C');
    assert(ft_toupper('F') == 'F');
    assert(ft_toupper('9') == '9');
    assert(ft_toupper('$') == '$');

    printf("All tests passed!\n");

    return 0;
}
