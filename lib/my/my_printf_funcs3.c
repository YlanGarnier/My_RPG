/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf_wrappers2
*/

#include "my.h"

void print_xx(va_list arg)
{
    char *str = my_itoa(va_arg(arg, unsigned int));
    char *converted = convert_base(str, "10", "16");

    for (int i = 0; converted[i] != '\0'; i++)
        if (converted[i] > 96)
            converted[i] -= 32;
    my_putstr(converted);
}
