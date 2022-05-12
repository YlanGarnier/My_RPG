/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf_utils.c
*/

#include "my.h"

char char_to_hex(int c)
{
    if (c >= 0 && c < 10)
        return '0' + c;
    else
        return 'a' + c - 10;
}
