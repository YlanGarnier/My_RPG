/*
** EPITECH PROJECT, 2021
** day8
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

static int count_words(char const *str, char const delim)
{
    int len = my_strlen(str);
    int i = 0, count = 0;

    for (; str[i] == delim; i++);
    for (int j = len - 1; j >= 0; j--) {
        while (str[j] == delim) {
            len--;
            j--;
        }
        break;
    }
    for (; i < len; i++) {
        if (str[i] != delim)
            continue;
        count++;
        while (str[i + 1] == delim)
            i++;
    }
    return (count + 1);
}

char **my_str_to_word_array(char const *str, char const delim)
{
    int pos = 0, len = 0, array_len = count_words(str, delim);
    char **words = malloc(sizeof(char *) * (array_len + 1));

    for (int i = 0; i < array_len + 1; i++)
        words[i] = NULL;
    for (int i = 0; i < array_len; i++) {
        while (str[pos] == delim)
            pos++;
        while (str[pos] != delim && str[pos] != '\0') {
            len++;
            pos++;
        }
        words[i] = malloc(sizeof(char) * len + 1);
        words[i][len] = '\0';
        for (int j = 0; j < len; j++)
            words[i][j] = str[(pos - len) + j];
        len = 0;
    }
    return (words);
}
