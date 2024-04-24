/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:11:20 by omartela          #+#    #+#             */
/*   Updated: 2024/04/19 14:45:17 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_nsubs(char const *s, char c)
{
	int	i;
	int	nsubs;

	i = 0;
	nsubs = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			nsubs++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nsubs);
}

static char	**free_memory(char **result, int subs_index)
{
	int	i;

	i = 0;
	if (!result[subs_index])
	{
		while (i < subs_index)
		{
			free(result[i]);
			i++;
		}
	}
	free(result[subs_index]);
	return (0);
}

static char **add_strings(char **result, const char *s, char c)
{
	int		subs_index;
	char	*ptr;
	int		i;
	int		start;

	subs_index = 0;
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		ptr = ft_strchr(&s[start], c);
		if (s[i] == c || s[i + 1] == '\0')
		{
			if (ptr == 0)
				result[subs_index] = ft_strdup(&s[start]);
			else
				result[subs_index] = ft_substr(s, start, ptr - &s[start]);
			if (!result[subs_index])
				return (free_memory(result, subs_index));
			while (s[i + 1] == c)
				i++;
			subs_index++;
			start = i + 1;
		}
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		nsubs;
	char	**result;

	if (!s)
		return (0);
	nsubs = count_nsubs(s, c);
	while (*s == c)
		++s;
	result = (char **)malloc((nsubs + 1) * sizeof(char *));
	if (!result)
		return (0);
	result = add_strings(result, s, c);
	result[nsubs] = 0;
	return (result);
}

void print_split_result(char **split_result) {
    if (split_result == NULL) {
        printf("{NULL}\n");
        return;
    }
    
    printf("{");
    for (int i = 0; split_result[i] != NULL; i++) {
        printf("\"%s\"", split_result[i]);
        if (split_result[i + 1] != NULL)
            printf(", ");
    }
    printf("}\n");
}

static void test_ft_split(const char *s, char c) {
    printf("Test for string: \"%s\" with delimiter '%c'\n", s, c);
    char **split_result = ft_split(s, c);
    printf("Split result: ");
    print_split_result(split_result);
    
    // Free allocated memory
    if (split_result != NULL) {
        for (int i = 0; split_result[i] != NULL; i++)
            free(split_result[i]);
        free(split_result);
    }
}

int main() {
    // Test 1
    test_ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');

    // Test 2
    test_ft_split("split  ||this|for|me|||||!|", '|');

    // Test 3
    test_ft_split("hello!", ' ');

    // Test 4
    test_ft_split("apples,oranges,bananas", ',');

    // Test 5
    test_ft_split("  hello", ' ');

    // Test 6
    test_ft_split("  hello  world", ' ');

    // Test 7
    test_ft_split("hello  world  ", ' ');

    // Test 8
    test_ft_split("apples,oranges;bananas", ';');

    // Test 9
    char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    test_ft_split(long_str, ' ');

    // Test 10
    test_ft_split(NULL, ' ');

    return 0;
}