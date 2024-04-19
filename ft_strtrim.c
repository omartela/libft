/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:55:28 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 18:56:52 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		++start;
	if (start > end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= 0)
		--end;
	ptr = malloc(sizeof(char) * (end - start) + 2);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &s1[start], (end - start) + 2);
	return (ptr);
}

// Test function
void test_strtrim(const char *s1, const char *set, const char *expected_result) {
    printf("Test: ft_strtrim(\"%s\", \"%s\")\n", s1, set);

    // Call the function under test
    char *result = ft_strtrim(s1, set);
	printf("My result %s\n", result);
	printf("Expected result %s\n", expected_result);

    // Compare results
    if ((expected_result == NULL && result == NULL) || strcmp(expected_result, result) == 0) {
        printf("Result: Passed\n");
    } else {
        printf("Result: Failed\n");
    }

	printf("\n");
    // Free memory
    free(result);
}

int main() {
    // Basic Test Cases
    test_strtrim("  Hello World  ", " ", "Hello World");
    test_strtrim("  Hello World  ", " H", "ello World");
    test_strtrim("Hello World", "", "Hello World");
    test_strtrim("", "", "");

    // Memory Allocation Tests
    test_strtrim(NULL, " ", NULL);
    test_strtrim("Hello World", NULL, NULL);

    // Edge Cases
    test_strtrim("Hello\nWorld", "\n", "Hello\nWorld");
    test_strtrim("Hello\0World", "\0", "Hello\0World");

    // Boundary Cases
    test_strtrim("A", "A", "");
    test_strtrim("AB", "AB", "");
    test_strtrim("ABC", "AB", "C");

    return 0;
}