/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:09:10 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 16:35:52 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*dest;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, len);
	ft_strlcat(dest, s2, len);
	return (dest);
}

void test_strjoin(const char *s1, const char *s2, const char *expected_result) {
    printf("Test: ft_strjoin(\"%s\", \"%s\")\n", s1, s2);

    // Call the function under test
    char *result = ft_strjoin(s1, s2);
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
    test_strjoin("Hello", "World", "HelloWorld");
    test_strjoin("", "World", "World");
    test_strjoin("Hello", "", "Hello");
    test_strjoin("", "", "");

    // Memory Allocation Tests
    test_strjoin(NULL, "World", NULL);
    test_strjoin("Hello", NULL, NULL);

    // Edge Cases
    test_strjoin("Hello\n", "World", "Hello\nWorld");
    test_strjoin("Hello\0", "World", "Hello\0World");

    // Boundary Cases
    test_strjoin("A", "B", "AB");
    test_strjoin("AB", "CD", "ABCD");

    return 0;
}