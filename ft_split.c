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
		if (s[i] == c || s[i + 1] == '\0')
		{
			nsubs++;
			while (s[i + 1] == c)
				i++;
		}
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
	int	subs_index;
	int	subs_len;
	int	i;
	int	start;

	subs_len = 0;
	subs_index = 0;
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i + 1] == '\0')
		{
			if (s[i + 1] == '\0')
				subs_len = i + 1 - start;
			else
				subs_len = i - start;
			result[subs_index] = ft_substr(s, start, subs_len);
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

	nsubs = count_nsubs(s, c);
	if (!s || !c)
		return (0);
	result = (char **)malloc((nsubs + 1) * sizeof(char *));
	if (!result)
		return (0);
	result = add_strings(result, s, c);
	result[nsubs] = 0;
	return (result);
}

/* void print_split_result(char **split_result) {
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

int main() {
    // Test 1
    printf("Test 1:\n");
    char	**test1 = ft_split("hello world", ' ');
    print_split_result(test1);

    // Test 2
    printf("Test 2:\n");
    char	**test2 = ft_split("", ' ');
    print_split_result(test2);

    // Test 3
    printf("Test 3:\n");
    char	**test3 = ft_split("a b c d", ' ');
    print_split_result(test3);

    // Test 4
    printf("Test 4:\n");
    char	**test4 = ft_split("apples,oranges,bananas", ',');
    print_split_result(test4);

    // Test 5
    printf("Test 5:\n");
    char	**test5 = ft_split("hello", ' ');
    print_split_result(test5);

    // Test 6
    printf("Test 6:\n");
    char	**test6 = ft_split("  hello  world", ' ');
    print_split_result(test6);

    // Test 7
    printf("Test 7:\n");
    char	**test7 = ft_split("hello  world  ", ' ');
    print_split_result(test7);

    // Test 8
    printf("Test 8:\n");
    char	**test8 = ft_split("apples,oranges;bananas", ';');
    print_split_result(test8);

    // Test 9
    printf("Test 9:\n");
    char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char	**test9 = ft_split(long_str, ' ');
    print_split_result(test9);

    // Test 10
    printf("Test 10:\n");
    char	**test10 = ft_split(NULL, ' ');
    print_split_result(test10);

    // Free allocated memory
    for (int i = 0; test1[i] != NULL; i++)
        free(test1[i]);
    free(test1);

    for (int i = 0; test2[i] != NULL; i++)
        free(test2[i]);
    free(test2);

    for (int i = 0; test3[i] != NULL; i++)
        free(test3[i]);
    free(test3);

    for (int i = 0; test4[i] != NULL; i++)
        free(test4[i]);
    free(test4);

    for (int i = 0; test5[i] != NULL; i++)
        free(test5[i]);
    free(test5);

    for (int i = 0; test6[i] != NULL; i++)
        free(test6[i]);
    free(test6);

    for (int i = 0; test7[i] != NULL; i++)
        free(test7[i]);
    free(test7);

    for (int i = 0; test8[i] != NULL; i++)
        free(test8[i]);
    free(test8);

    for (int i = 0; test9[i] != NULL; i++)
        free(test9[i]);
    free(test9);

	free (test10);
    return 0;
} */