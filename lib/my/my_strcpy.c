/*
** EPITECH PROJECT, 2021
** day6
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int src_len = my_strlen(src);
    for (int i = 0; src[i] != '\0'; i += 1) {
        dest[i] = src[i];
    }
    dest[src_len] = '\0';
    return dest;
}
