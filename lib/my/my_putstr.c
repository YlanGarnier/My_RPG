/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const* str)
{
    int counter = 0;
    while (str[counter] != '\0') {
        my_putchar(str[counter]);
        counter += 1;
    }
    return (0);
}
