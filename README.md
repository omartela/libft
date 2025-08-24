# Libft - A Custom C Library

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/omartela/libft)
[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

**Libft** is a comprehensive C library that reimplements many standard library functions along with additional utility functions. This library serves as a foundation for C programming projects, providing reliable, well-tested implementations of essential functions.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Function Documentation](#function-documentation)
  - [Character Classification](#character-classification)
  - [Character Conversion](#character-conversion)
  - [String Functions](#string-functions)
  - [Memory Functions](#memory-functions)
  - [Conversion Functions](#conversion-functions)
  - [File Descriptor Functions](#file-descriptor-functions)
  - [Additional String Utilities](#additional-string-utilities)
  - [Linked List Functions (Bonus)](#linked-list-functions-bonus)
  - [Extended Functions](#extended-functions)
- [Examples](#examples)
- [Testing](#testing)

## 🎯 Overview

This library contains **50+ functions** across multiple categories, totaling over **1,600 lines** of carefully crafted C code. It includes:

- **Standard libc reimplementations** - Drop-in replacements for common C library functions
- **Additional string utilities** - Enhanced string manipulation functions  
- **Linked list operations** - Complete linked list manipulation toolkit
- **File reading utilities** - Line-by-line file reading with `get_next_line`
- **Memory management** - Advanced memory allocation and reallocation functions

All functions are implemented following **strict coding standards** with comprehensive error handling and memory safety.

## ✨ Features

- ⚡ **High Performance** - Optimized implementations of standard functions
- 🛡️ **Memory Safe** - Comprehensive bounds checking and null pointer protection
- 🧪 **Well Tested** - Thoroughly tested implementations
- 📝 **Well Documented** - Clear documentation for all functions
- 🔗 **Modular Design** - Use only the functions you need
- 🎯 **Zero Dependencies** - Only uses system libraries (stdlib.h, unistd.h)

## 🚀 Installation

### Prerequisites

- GCC or Clang compiler
- GNU Make
- POSIX-compliant system (Linux, macOS, Unix)

### Building the Library

```bash
# Clone the repository
git clone https://github.com/omartela/libft.git
cd libft

# Build the library
make

# Build with bonus functions (linked list operations)
make bonus

# Clean object files
make clean

# Clean everything (including libft.a)
make fclean

# Rebuild everything
make re
```

This will generate `libft.a`, a static library that you can link with your projects.

### Integration with Your Project

```bash
# Compile your program with libft
gcc -Wall -Wextra -Werror your_program.c -L. -lft -o your_program

# Or include the header and link the library
#include "libft.h"
```

## 💻 Usage

### Basic Example

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    // String manipulation
    char *str = ft_strdup("Hello, World!");
    char *upper = ft_strmapi(str, &ft_toupper);
    
    // String splitting
    char **words = ft_split("apple,banana,cherry", ',');
    
    // Memory operations
    char *buffer = ft_calloc(100, sizeof(char));
    ft_strlcpy(buffer, "Test string", 100);
    
    // Number conversion
    char *number_str = ft_itoa(42);
    int number = ft_atoi("123");
    
    // File operations
    int fd = open("file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    
    // Cleanup
    free(str);
    free(upper);
    free(buffer);
    free(number_str);
    free(line);
    close(fd);
    
    return (0);
}
```

## 📚 Function Documentation

### Character Classification

Functions to test character properties:

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `ft_isalpha` | Check if character is alphabetic | `int c` | Non-zero if true, 0 if false |
| `ft_isdigit` | Check if character is a digit | `int c` | Non-zero if true, 0 if false |
| `ft_isalnum` | Check if character is alphanumeric | `int c` | Non-zero if true, 0 if false |
| `ft_isascii` | Check if character is ASCII | `int c` | Non-zero if true, 0 if false |
| `ft_isprint` | Check if character is printable | `int c` | Non-zero if true, 0 if false |

### Character Conversion

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `ft_tolower` | Convert character to lowercase | `int c` | Lowercase character or unchanged |
| `ft_toupper` | Convert character to uppercase | `int c` | Uppercase character or unchanged |

### String Functions

Standard string manipulation functions:

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `ft_strlen` | Calculate string length | `const char *s` | Length of string |
| `ft_strchr` | Locate character in string | `const char *s, int c` | Pointer to first occurrence or NULL |
| `ft_strrchr` | Locate character in string (reverse) | `const char *s, int c` | Pointer to last occurrence or NULL |
| `ft_strncmp` | Compare strings (n characters) | `const char *s1, const char *s2, size_t n` | Comparison result |
| `ft_strlcpy` | Copy string with size limit | `char *dst, const char *src, size_t size` | Length of source string |
| `ft_strlcat` | Concatenate strings with size limit | `char *dst, const char *src, size_t size` | Total length of created string |
| `ft_strnstr` | Locate substring | `const char *str, const char *to_find, size_t len` | Pointer to substring or NULL |
| `ft_strdup` | Duplicate string | `const char *s` | Pointer to duplicated string |

### Memory Functions

Low-level memory manipulation:

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `ft_memset` | Fill memory with constant byte | `void *b, int c, size_t len` | Pointer to memory area |
| `ft_bzero` | Zero a byte string | `void *s, size_t n` | None (void) |
| `ft_memcpy` | Copy memory area | `void *dst, const void *src, size_t n` | Pointer to destination |
| `ft_memmove` | Copy memory area (handles overlap) | `void *dst, const void *src, size_t len` | Pointer to destination |
| `ft_memchr` | Locate byte in memory | `const void *s, int c, size_t n` | Pointer to byte or NULL |
| `ft_memcmp` | Compare memory areas | `const void *s1, const void *s2, size_t n` | Comparison result |
| `ft_calloc` | Allocate and zero memory | `size_t count, size_t size` | Pointer to allocated memory |

### Conversion Functions

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `ft_atoi` | Convert string to integer | `const char *str` | Integer value |
| `ft_itoa` | Convert integer to string | `int n` | Pointer to string representation |

### File Descriptor Functions

Output functions for file descriptors:

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `ft_putchar_fd` | Output character to file descriptor | `char c, int fd` | None (void) |
| `ft_putstr_fd` | Output string to file descriptor | `char *s, int fd` | None (void) |
| `ft_putendl_fd` | Output string + newline to file descriptor | `char *s, int fd` | None (void) |
| `ft_putnbr_fd` | Output integer to file descriptor | `int n, int fd` | None (void) |

### Additional String Utilities

Enhanced string manipulation functions:

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `ft_substr` | Extract substring | `char const *s, unsigned int start, size_t len` | Pointer to substring |
| `ft_strjoin` | Concatenate two strings | `char const *s1, char const *s2` | Pointer to new string |
| `ft_strtrim` | Trim characters from string | `char const *s1, char const *set` | Pointer to trimmed string |
| `ft_split` | Split string by delimiter | `char const *s, char c` | Array of strings |
| `ft_strmapi` | Apply function to each character | `char const *s, char (*f)(unsigned int, char)` | Pointer to new string |
| `ft_striteri` | Apply function to each character (in-place) | `char *s, void (*f)(unsigned int, char *)` | None (void) |

### Linked List Functions (Bonus)

Complete toolkit for linked list manipulation:

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `ft_lstnew` | Create new list element | `void *content` | Pointer to new element |
| `ft_lstadd_front` | Add element at beginning | `t_list **lst, t_list *new` | None (void) |
| `ft_lstadd_back` | Add element at end | `t_list **lst, t_list *new` | None (void) |
| `ft_lstsize` | Count list elements | `t_list *lst` | Number of elements |
| `ft_lstlast` | Get last element | `t_list *lst` | Pointer to last element |
| `ft_lstdelone` | Delete one element | `t_list *lst, void (*del)(void *)` | None (void) |
| `ft_lstclear` | Delete entire list | `t_list **lst, void (*del)(void *)` | None (void) |
| `ft_lstiter` | Apply function to each element | `t_list *lst, void (*f)(void *)` | None (void) |
| `ft_lstmap` | Create new list with function applied | `t_list *lst, void *(*f)(void *), void (*del)(void *)` | Pointer to new list |

#### Linked List Structure

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
```

### Extended Functions

Additional utility functions beyond standard libft:

| Function | Description | Parameters | Return |
|----------|-------------|------------|--------|
| `get_next_line` | Read file line by line | `int fd` | Next line or NULL if EOF/error |
| `ft_realloc` | Reallocate memory | `void *ptr, size_t old_size, size_t new_size` | Pointer to reallocated memory |
| `ft_recalloc` | Reallocate and zero memory | `void *ptr, size_t old_size, size_t new_size` | Pointer to reallocated memory |
| `ft_strndup` | Duplicate string with length limit | `const char *s1, size_t n` | Pointer to duplicated string |
| `ft_string_replace` | Replace substring in string | `char *str, char *delimiter, char *insert` | Pointer to new string |

## 💡 Examples

### String Manipulation

```c
#include "libft.h"

int main(void)
{
    char *text = "  Hello, World!  ";
    char *trimmed = ft_strtrim(text, " ");        // "Hello, World!"
    char **words = ft_split(trimmed, ',');        // ["Hello", " World!"]
    char *joined = ft_strjoin(words[0], words[1]); // "Hello World!"
    
    printf("Original: '%s'\n", text);
    printf("Trimmed: '%s'\n", trimmed);
    printf("Joined: '%s'\n", joined);
    
    // Cleanup
    free(trimmed);
    free(words[0]);
    free(words[1]);
    free(words);
    free(joined);
    
    return (0);
}
```

### Linked List Operations

```c
#include "libft.h"

int main(void)
{
    t_list *list = NULL;
    
    // Add elements
    ft_lstadd_front(&list, ft_lstnew("World"));
    ft_lstadd_front(&list, ft_lstnew("Hello"));
    ft_lstadd_back(&list, ft_lstnew("!"));
    
    // Print list size
    printf("List size: %d\n", ft_lstsize(list)); // Output: 3
    
    // Iterate through list
    t_list *current = list;
    while (current)
    {
        printf("%s ", (char *)current->content);
        current = current->next;
    }
    printf("\n"); // Output: Hello World !
    
    // Cleanup
    ft_lstclear(&list, &free);
    
    return (0);
}
```

### File Reading with get_next_line

```c
#include "libft.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;
    int line_count = 0;
    
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", ++line_count, line);
        free(line);
    }
    
    close(fd);
    printf("Total lines read: %d\n", line_count);
    
    return (0);
}
```

## 🧪 Testing

The library has been thoroughly tested with various test suites. To test the functions:

```bash
# Build the library
make

# Test basic functionality
echo "Testing ft_strlen..."
echo '#include "libft.h"
#include <stdio.h>
int main(void) {
    printf("Length of \"Hello\": %zu\n", ft_strlen("Hello"));
    return 0;
}' > test.c && gcc test.c -L. -lft -o test && ./test

# Clean up
rm test.c test
```

### Memory Testing

It's recommended to test with valgrind for memory leaks:

```bash
valgrind --leak-check=full ./your_program
```

## 👨‍💻 Author

**omartela** - [@omartela](https://github.com/omartela)

- Email: omartela@student.hive.fi
- School: Hive Helsinki (42 Network)

## 🙏 Acknowledgments

- **42 School** for the project foundation and coding standards
- **Hive Helsinki** for the educational environment
- The **C standard library** documentation and specifications

⭐ **Star this repository if you find it helpful!**

*Built with ❤️ for the 42 programming community*
