/*
** EPITECH PROJECT, 2021
** day8
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int src_len = my_strlen(src) + 1;
    char *result = malloc(sizeof(char) * src_len);
    if (result != NULL)
        my_strcpy(result, src);
    return result;
}
