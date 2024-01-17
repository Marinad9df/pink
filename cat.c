#include "libft.h"
#include <stdlib.h>

// Function to allocate memory and split the string
static void ft_allocate(char **tab, char const *s, char sep) {
    char **tab_p;
    char const *tmp;
    tmp = s;
    tab_p = tab;
    while (*tmp) {
        while (*s == sep)
            ++s;
        tmp = s;
        while (*tmp && *tmp != sep)
            ++tmp;
        if (*tmp == sep || tmp > s) {
            *tab_p = ft_substr(s, 0, tmp - s);  // Allocate and store the substring
            s = tmp;
            ++tab_p;
        }
    }
    *tab_p = NULL;  // Set the last element of the array to NULL
}

// Function to count the number of words in the string
static int ft_count_words(char const *s, char sep) {
    int word_count = 0;
    while (*s) {
        while (*s == sep)
            ++s;
        if (*s)
            ++word_count;
        while (*s && *s != sep)
            ++s;
    }
    return (word_count);
}

// Main function to split the string
char **ft_split(char const *s, char c) {
    char **new;
    int size;
    if (!s)
        return (NULL);
    size = ft_count_words(s, c);  // Count the number of words
    new = (char **)malloc(sizeof(char *) * (size + 1));  // Allocate memory for the array of strings
    if (!new)
        return (NULL);
    ft_allocate(new, s, c);  // Split the string and store the substrings
    return (new);
}
