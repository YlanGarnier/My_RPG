/*
** EPITECH PROJECT, 2021
** day07
** File description:
** my_strcat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i = 0;
    for (; src[i] != '\0' && i < nb; i += 1) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}
