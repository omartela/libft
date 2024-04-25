/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:30:09 by omartela          #+#    #+#             */
/*   Updated: 2024/04/22 11:30:38 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <assert.h>
#include "string.h"

// Function to compare results of ft_calloc and calloc
void compare_results_calloc(size_t nmemb, size_t size) {
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

void test_ft_isalpha() 
{
    // Test cases for lowercase letters
    printf("Test cases for lowercase letters:\n");
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isalpha('a')); // should return 1
    printf("Actual Output: %d\n", ft_isalpha('z')); // should return 1

    // Test cases for uppercase letters
    printf("\nTest cases for uppercase letters:\n");
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isalpha('A')); // should return 1
    printf("Actual Output: %d\n", ft_isalpha('Z')); // should return 1

    // Test cases for non-alphabetic characters
    printf("\nTest cases for non-alphabetic characters:\n");
    printf("Expected Output: 0\n");
    printf("Actual Output: %d\n", ft_isalpha('0')); // should return 0
    printf("Actual Output: %d\n", ft_isalpha('&')); // should return 0
}

void test_ft_isascii() 
{
    printf("Test cases for ft_isascii:\n");
    
    // Test cases for valid ASCII characters
    printf("Expected Output: 1\n");
    printf("Actual Output: %d\n", ft_isascii(0)); // should return 1
    printf("Actual Output: %d\n", ft_isascii(65)); // should return 1 ('A')
    printf("Actual Output: %d\n", ft_isascii(127)); // should return 1 (DEL)

    // Test cases for non-ASCII characters
    printf("Expected Output: 0\n");
    printf("Actual Output: %d\n", ft_isascii(-1)); // should return 0
    printf("Actual Output: %d\n", ft_isascii(128)); // should return 0
    printf("Actual Output: %d\n", ft_isascii(255)); // should return 0
}

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
    printf("Actual Output: %d\n\n\n", ft_isprint(0)); // should return 0 (null character)
}

void test_memmove() {
    // Test case 1: Moving from src to dst
    char str1[] = "1234567890";
    char str2[20] = "abcdefghij";
    char str22[20] = "abcdefghij";
    ft_memmove(str2 + 3, str1 + 2, 5);
    printf("Test Case 1 (ft_memmove): %s\n", str2);
    memmove(str22 + 3, str1 + 2, 5);
    printf("Test Case 1 (memmove): %s\n", str22);
    printf("Test Case 1 comparison: %s\n", strcmp(str2, str22) == 0 ? "Passed" : "Failed");

    // Test case 2: Moving from dst to src
    char str3[] = "1234567890";
    char str32[] = "1234567890";
    ft_memmove(str3 + 2, str3 + 4, 5);
    printf("Test Case 2 (ft_memmove): %s\n", str3);
    memmove(str32 + 2, str32 + 4, 5);
    printf("Test Case 2 (memmove): %s\n", str32);
    printf("Test Case 2 comparison: %s\n", strcmp(str3, str32) == 0 ? "Passed" : "Failed");

    // Test case 3: Moving overlapping memory region forward
    char str4[] = "1234567890";
    char str42[] = "1234567890";
    ft_memmove(str4 + 4, str4 + 2, 4);
    printf("Test Case 3 (ft_memmove): %s\n", str4);
    memmove(str42 + 4, str42 + 2, 4);
    printf("Test Case 3 (memmove): %s\n", str42);
    printf("Test Case 3 comparison: %s\n", strcmp(str4, str42) == 0 ? "Passed" : "Failed");

    // Test case 4: Moving overlapping memory region backward
    char str5[] = "1234567890";
    char str52[] = "1234567890";
    ft_memmove(str5 + 2, str5 + 4, 4);
    printf("Test Case 4 (ft_memmove): %s\n", str5);
    memmove(str52 + 2, str52 + 4, 4);
    printf("Test Case 4 (memmove): %s\n", str52);
    printf("Test Case 4 comparison: %s\n", strcmp(str5, str52) == 0 ? "Passed" : "Failed");

    // Test case 5: Moving non-overlapping memory region
    char str6[] = "1234567890";
    char str62[] = "1234567890";
    ft_memmove(str6 + 10, str6, 1);
    printf("Test Case 5 (ft_memmove): %s\n", str6); // Output should be: "1234567890123"
    memmove(str62 + 10, str62, 1);
    printf("Test Case 5 (memmove): %s\n", str62);
    printf("Test Case 5 comparison: %s\n", strcmp(str6, str62) == 0 ? "Passed" : "Failed");

    // Test case 6: Moving non-overlapping memory region (dst < src)
    char str7[] = "1234567890";
    char str72[] = "1234567890";
    ft_memmove(str7, str7 + 2, 5);
    printf("Test Case 6 (ft_memmove): %s\n", str7); // Output should be: "3456787890"
    memmove(str72, str72 + 2, 5);
    printf("Test Case 6 (memmove): %s\n", str72);
    printf("Test Case 6 comparison: %s\n", strcmp(str7, str72) == 0 ? "Passed" : "Failed");

    // Test case 7: Moving non-overlapping memory region (dst > src)
    char str8[] = "1234567890";
    char str82[] = "1234567890";
    ft_memmove(str8 + 2, str8, 5);
    printf("Test Case 7 (ft_memmove): %s\n", str8); // Output should be: "121234567890"
    memmove(str82 + 2, str82, 5);
    printf("Test Case 7 (memmove): %s\n", str82);
    printf("Test Case 7 comparison: %s\n\n", strcmp(str8, str82) == 0 ? "Passed" : "Failed");
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

void test_memcpy()
{
	// Test 1: Equal Memory Blocks
    char str1[] = "hello";
    char str2[] = "hello";
    int result1_ft = ft_memcmp(str1, str2, strlen(str1));
    int result1_memcmp = memcmp(str1, str2, strlen(str1));
    printf("Test 1: ft_memcmp result = %d, memcmp result = %d\n", result1_ft, result1_memcmp);

    // Test 2: Different Memory Blocks with Same Size
    char str3[] = "hello";
    char str4[] = "hallo";
    int result2_ft = ft_memcmp(str3, str4, strlen(str3));
    int result2_memcmp = memcmp(str3, str4, strlen(str3));
    printf("Test 2: ft_memcmp result = %d, memcmp result = %d\n", result2_ft, result2_memcmp);

    // Test 3: Different Memory Blocks with Different Sizes
    char str5[] = "hello";
    char str6[] = "hello world";
    int result3_ft = ft_memcmp(str5, str6, strlen(str5));
    int result3_memcmp = memcmp(str5, str6, strlen(str5));
    printf("Test 3: ft_memcmp result = %d, memcmp result = %d\n", result3_ft, result3_memcmp);

	char src[5] = "test";
	char dest[5];
	puts(ft_memcpy(dest, src, 5));
	//printf("%s", ft_memcpy(dest, src, 5));
}

void test_ft_strchr(void)
{
    // Test case 1: Search for character 'c' in a string where 'c' is present
    const char *str1 = "hello";
    char target1 = 'e';
    char *result1 = ft_strchr(str1, target1);
    printf("Test case 1: Search for '%c' in \"%s\"\n", target1, str1);
    printf("Expected result: Pointer to 'e'\n");
    printf("Actual result: Pointer to '%c'\n\n", *result1);
    assert(result1 == &str1[1]);

    // Test case 2: Search for character 'c' in a string where 'c' is not present
}

void test_ft_strdup(void)
{
    // Test case 1: Duplicate a non-empty string
    const char *src1 = "hello";
    char *result1 = ft_strdup(src1);
    printf("Test case 1: Duplicate \"%s\"\n", src1);
    printf("Expected result: \"%s\"\n", src1);
    printf("Actual result: \"%s\"\n\n", result1);
    assert(strcmp(result1, src1) == 0);
    free(result1); // Free allocated memory

    // Test case 2: Duplicate an empty string
    const char *src2 = "";
    char *result2 = ft_strdup(src2);
    printf("Test case 2: Duplicate \"%s\"\n", src2);
    printf("Expected result: \"%s\"\n", src2);
    printf("Actual result: \"%s\"\n\n", result2);
    assert(strcmp(result2, src2) == 0);
    free(result2); // Free allocated memory

    // Test case 3: Duplicate a string containing special characters
    const char *src3 = "special characters: @#$%^&*()";
    char *result3 = ft_strdup(src3);
    printf("Test case 3: Duplicate \"%s\"\n", src3);
    printf("Expected result: \"%s\"\n", src3);
    printf("Actual result: \"%s\"\n\n", result3);
    assert(strcmp(result3, src3) == 0);
    free(result3); // Free allocated memory

    // Test case 4: Duplicate a string with null terminator in the middle
    const char *src4 = "hello\0world";
    char *result4 = ft_strdup(src4);
    printf("Test case 4: Duplicate \"%s\"\n", src4);
    printf("Expected result: \"%s\"\n", src4);
    printf("Actual result: \"%s\"\n\n", result4);
    assert(strcmp(result4, src4) == 0);
    free(result4); // Free allocated memory
}

void test_strlcat()
{
	char dest1[20] = "Hello";
    char src1[] = "World";
    unsigned int size1 = sizeof(dest1);

    char dest2[20] = "Hello";
    char src2[] = "World";
    unsigned int size2 = sizeof(dest2);

    char dest3[10] = "Hello";
    char src3[] = "World";
    unsigned int size3 = sizeof(dest3);

	char dest4[10] = "Hello";
	char src4[] = "World";
	unsigned int size4 = sizeof(dest4);

    printf("Test 1 (ft_strlcat): %lu\n", ft_strlcat(dest1, src1, size1));
    printf("Test 1 (strlcat): %lu\n", strlcat(dest2, src2, size2));

    printf("Test 2 (ft_strlcat): %lu\n", ft_strlcat(dest3, src3, size3));
    printf("Test 2 (strlcat): %lu\n", strlcat(dest4, src4, size4));

    printf("Modified dest1 ft_strlcat: %s\n", dest1);
    printf("Modified dest2 strlcat: %s\n", dest2);
    printf("Modified dest3 ft_strlcat: %s\n", dest3);
	printf("Modified dest4 strlcat: %s\n\n\n", dest4);
}

void test_strlcpy()
{
	// Test cases for ft_strlcpy
    char destination[20];
    const char *source = "Hello, world!";
    size_t result;

    // Test case 1: Small buffer
    result = ft_strlcpy(destination, source, 5);
    printf("ft_strlcpy result: %zu, dst: '%s'\n", result, destination);

    // Test case 2: Large buffer
	char src[400];
    result = ft_strlcpy(destination, src, sizeof(destination));
    printf("ft_strlcpy result: %zu, dst: '%s'\n", result, destination);

    // Test case 3: Empty source string
    const char *empty_src = "";
    result = ft_strlcpy(destination, empty_src, sizeof(destination));
    printf("ft_strlcpy result: %zu, dst: '%s'\n", result, destination);

    // Function calls for original strlcpy for comparison

    // Test case 1: Small buffer
    result = strlcpy(destination, source, 5);
    printf("strlcpy result: %zu, dst: '%s'\n", result, destination);

    // Test case 2: Large buffer
    result = strlcpy(destination, src, sizeof(destination));
    printf("strlcpy result: %zu, dst: '%s'\n", result, destination);

    // Test case 3: Empty source string
    result = strlcpy(destination, empty_src, sizeof(destination));
    printf("strlcpy result: %zu, dst: '%s'\n\n", result, destination);
}

void test_strncmp()
{
	char str1[] = "Hella";
    char str2[] = "Hello";
    unsigned int n1 = 5;

    char str3[] = "Hello";
    char str4[] = "World";
    unsigned int n2 = 3;

    char str5[] = "Apples";
    char str6[] = "Bananas";
    unsigned int n3 = 7;

    printf("Test 1 (ft_strncmp): %d\n", ft_strncmp(str1, str2, n1));
    printf("Test 1 (strncmp): %d\n", strncmp(str1, str2, n1));

    printf("Test 2 (ft_strncmp): %d\n", ft_strncmp(str3, str4, n2));
    printf("Test 2 (strncmp): %d\n", strncmp(str3, str4, n2));

    printf("Test 3 (ft_strncmp): %d\n", ft_strncmp(str5, str6, n3));
    printf("Test 3 (strncmp): %d\n", strncmp(str5, str6, n3));
}

void test_strnstr()
{
	char haystack[20] = "Hello.Hive.Five";
	char haystack2[20] = "\0";
	char needle[10] = "ve";
	char needle2[10] = ".Ha";
	char needle3[10] = "\0";
	size_t len = 10;
	size_t len2 = 1;
	size_t len3 = 0;
	char *result, *result3, *result5, *result7, *result8;
	char *result2, *result4, *result6;

	result = strnstr(haystack, needle, len);
	result2 = ft_strnstr(haystack, needle, len);
	printf("The substring is: %s\n", result);
	printf("The substring is: %s\n\n", result2);

	result = strnstr(haystack, needle, len2);
	result2 = ft_strnstr(haystack, needle, len2);
	printf("The substring is: %s\n", result);
	printf("The substring is: %s\n\n", result2);

	result = strnstr(haystack, needle, len3);
	result2 = ft_strnstr(haystack, needle, len3);
	printf("The substring is: %s\n", result);
	printf("The substring is: %s\n\n", result2);

	result3 = strnstr(haystack, needle2, len);
	result4 = ft_strnstr(haystack, needle2, len);
	printf("The substring is: %s\n", result3);
	printf("The substring is: %s\n\n", result4);

	result3 = strnstr(haystack, needle2, len2);
	result4 = ft_strnstr(haystack, needle2, len2);
	printf("The substring is: %s\n", result3);
	printf("The substring is: %s\n\n", result4);

	result3 = strnstr(haystack, needle2, len3);
	result4 = ft_strnstr(haystack, needle2, len3);
	printf("The substring is: %s\n", result3);
	printf("The substring is: %s\n\n", result4);

	result5 = strnstr(haystack, needle3, len);
	result6 = ft_strnstr(haystack, needle3, len);
	printf("The substring is: %s\n", result5);
	printf("The substring is: %s\n\n", result6);

	result5 = strnstr(haystack, needle3, len2);
	result6 = ft_strnstr(haystack, needle3, len2);
	printf("The substring is: %s\n", result5);
	printf("The substring is: %s\n\n", result6);

	result5 = strnstr(haystack, needle3, len3);
	result6 = ft_strnstr(haystack, needle3, len3);
	printf("The substring is: %s\n", result5);
	printf("The substring is: %s\n\n", result6);

	result7 = strnstr(haystack2, needle, len);
	result8 = ft_strnstr(haystack2, needle, len);
	printf("The substring is: %s\n", result7);
	printf("The substring is: %s\n\n", result8);
}

void test_strrchr()
{
	const char str[] = "Hello.Hive.Five";
	const char ch = '.';
	const char ch2 = 'D';
	const char ch3 = '\0';
	char *result, *result2, *result3;
	char *result4, *result5, *result6;

	result = strrchr(str, ch);
	result2 = ft_strrchr(str, ch);

	printf("String after orig |%c| is - |%s|\n", ch, result);
	printf("String after mine |%c| is - |%s|\n", ch, result2);

	result3 = strrchr(str, ch2);
	result4 = ft_strrchr(str, ch2);

	printf("String after orig |%c| is - |%s|\n", ch2, result3);
	printf("String after mine |%c| is - |%s|\n", ch2, result4);

	result5 = strrchr(str, ch3);
	result6 = ft_strrchr(str, ch3);

	printf("String after orig |%c| is - |%s|\n", ch3, result5);
	printf("String after mine |%c| is - |%s|\n", ch3, result6);
}

void print_split_result(char **split_result) {
    if (split_result == NULL) {
        printf("{NULL}\n");
        return;
    }
    
    printf("{"); 
    for (int i = 0; split_result[i]; i++) {
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
    // Test 1: Allocating memory for an array of integers
    compare_results_calloc(5, sizeof(int));

    // Test 2: Allocating memory for an array of floats
    compare_results_calloc(10, sizeof(float));

    // Test 3: Allocating memory for an array of structs
    struct ExampleStruct {
        int a;
        float b;
        char c;
    };
    compare_results_calloc(3, sizeof(struct ExampleStruct));

    // Test 4: Allocating memory for a string
    compare_results_calloc(1, 20 * sizeof(char));

    // Add more tests here...

	test_ft_isalnum();
	test_ft_isalpha();
	test_ft_isascii();
	test_ft_isdigit();
	test_ft_isprint();

	test_memmove();

	test_ft_strchr();
    printf("All ft_strchr tests passed successfully!\n\n");

	test_ft_strdup();
    printf("All ft_strdup tests passed successfully!\n\n");

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

	test_strlcat();
	test_strlcpy();
	test_strncmp();
	test_strnstr();
	test_strrchr();

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

	char const src[19] = "Hello Hive";
	char const src1[7] = "";
	char *result1, *result3, *result5, *result7, *result8;
	char *result2, *result4, *result6;

	result1 = ft_substr(src, 3, 3);
	printf("The substring is: %s\n", result1);
	result2 = ft_substr(src, 3, 0);
	printf("The substring is: %s\n", result2);
	result3 = ft_substr(src, 3, 1);
	printf("The substring is: %s\n", result3);
	result4 = ft_substr(src, 3, 20);
	printf("The substring is: %s\n", result4);
	result5 = ft_substr(src, 0, 3);
	printf("The substring is: %s\n", result5);
	result6 = ft_substr(src, 20, 3);
	printf("The substring is: %s\n", result6);
	result7 = ft_substr(src1, 3, 3);
	printf("The substring is: %s\n", result7);
	result8 = ft_substr(src1, 0, 0);
	printf("The substring is: %s\n", result8);

	printf("%c", ft_tolower('s'));

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

    printf("All tests lower and upper tests passed!\n\n");

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

	// Test 11
    test_ft_split("test", 0);

	test_ft_split("", 'a');
	test_ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');

    return 0;
}