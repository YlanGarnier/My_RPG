/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strcapitalize
*/

#include "my.h"

static int is_pre_mark(char c)
{
    if (c == ' ' || c == '+' || c == '-')
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        if (is_pre_mark(str[i]) == 1 && str[i + 1] >= 'a' && str[i + 1] <= 'z')
            str[i + 1] = str[i + 1] - 32;
    }
    return str;
}
