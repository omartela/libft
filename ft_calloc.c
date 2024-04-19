/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:49:50 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 12:57:08 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	*ptr;

	ptr = malloc(nitems * size);
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, size * nitems);
	return (ptr);
}

#include <string.h> // for memcmp function
#include <stdio.h>
// Function to compare results of ft_calloc and calloc
void compare_results(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void *result_ft = ft_calloc(nmemb, size);
    void *result_calloc = calloc(nmemb, size);
    
    // Compare the memory blocks allocated by ft_calloc and calloc
    int cmp_result = memcmp(result_ft, result_calloc, total_size);
    
    printf("Size of each element: %zu\n", size);
    printf("Number of elements: %zu\n", nmemb);
    printf("Total size (bytes): %zu\n", total_size);
    
    if (cmp_result == 0) {
        printf("Memory blocks match!\n");
    } else {
        printf("Memory blocks do not match!\n");
    }
    
    // Free memory allocated by ft_calloc and calloc
    free(result_ft);
    free(result_calloc);
    printf("\n");
}

int main() {
    // Test 1: Allocating memory for an array of integers
    compare_results(5, sizeof(int));

    // Test 2: Allocating memory for an array of floats
    compare_results(10, sizeof(float));

    // Test 3: Allocating memory for an array of structs
    struct ExampleStruct {
        int a;
        float b;
        char c;
    };
    compare_results(3, sizeof(struct ExampleStruct));

    // Test 4: Allocating memory for a string
    compare_results(1, 20 * sizeof(char));

    // Add more tests here...

    return 0;
}
