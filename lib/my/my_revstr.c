/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_revstr
*/

#include "my.h"
#include <stdlib.h>

char *my_revstr(char *str)
{
    int i;
    int j;
    char a;
    int len = my_strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
    return str;
}
