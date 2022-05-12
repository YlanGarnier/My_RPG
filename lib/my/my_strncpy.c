/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int src_len = my_strlen(src);
    for (int i = 0; src[i] != '\0' && i < n; i += 1) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}
