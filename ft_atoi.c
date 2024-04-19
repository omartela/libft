/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:49:10 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 12:49:34 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	string_to_integer(const char *str)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	atoi;
	int	sign;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f' || *str == '\n')
	{
		++str;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		++str;
	}
	atoi = string_to_integer(str);
	atoi = sign * atoi;
	return (atoi);
}

#include <stdio.h>
// Function to compare results of ft_atoi and atoi
void compare_results(const char *str) {
    int result_ft = ft_atoi(str);
    int result_atoi = atoi(str);
    printf("String: \"%s\"\n", str);
    printf("ft_atoi result: %d\n", result_ft);
    printf("atoi result: %d\n", result_atoi);
    if (result_ft == result_atoi) {
        printf("Results match!\n");
    } else {
        printf("Results do not match!\n");
    }
    printf("\n");
}

int main() 
{
    // Test 1: Positive number
    const char *str1 = "12345";
    compare_results(str1);

    // Test 2: Negative number
    const char *str2 = "-54321";
    compare_results(str2);

    // Test 3: Zero
    const char *str3 = "0";
    compare_results(str3);

    // Test 4: Number with leading spaces
    const char *str4 = "   9876";
    compare_results(str4);

    // Test 5: Number with trailing spaces
    const char *str5 = "54321   ";
    compare_results(str5);

    // Test 6: Number with leading and trailing spaces
    const char *str6 = "   -123   ";
    compare_results(str6);

    // Test 7: String with leading characters
    const char *str7 = "abc123";
    compare_results(str7);

    // Test 8: String with trailing characters
    const char *str8 = "123def";
    compare_results(str8);

    // Test 9: String with both leading and trailing characters
    const char *str9 = "xyz456xyz";
    compare_results(str9);

    // Add more tests here...
    const char *str10 = "--456";
    compare_results(str10);

    const char *str11 = "++456";
    compare_results(str11);

    const char *str12 = "-2147483648";
    compare_results(str12);

    // int max
    const char *str13 = "2147483647";
    compare_results(str13);

    // int min
    const char *str14 = "–2147483648";
    compare_results(str14);
}
