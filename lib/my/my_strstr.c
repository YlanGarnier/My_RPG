/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strst
*/

#include "my.h"

static int check_equal(char *str1, char *str2)
{
    while (1) {
        if (*str2 == 0)
            return (1);
        if (*str1++ != *str2++)
            return (0);
    }
}

char *my_strstr(char *str, char *sub)
{
    char *str1, *str2;

    str2 = sub;
    if (*str2 == 0)
        return (str);
    for (; *str != 0; str += 1) {
        if (*str != *str2)
            continue;
        str1 = str;
        if (check_equal(str1, str2) == 1)
            return (str);
        else
            break;
        str2 = sub;
    }
    return ((void *)0);
}
