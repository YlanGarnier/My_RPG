/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_str_islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    if (str[0] == '\0')
        return 1;
    if (my_str_isalpha(str) == 0)
        return 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            return 0;
    }
    return 1;
}
