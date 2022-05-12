/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf_wrappers2
*/

#include "my.h"
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

void print_x(va_list arg)
{
    char *str = my_itoa(va_arg(arg, unsigned int));

    my_putstr(convert_base(str, "10", "16"));
}

void print_b(va_list arg)
{
    char *str = my_itoa(va_arg(arg, unsigned int));

    my_putstr(convert_base(str, "10", "2"));
}

void print_u(va_list arg)
{
    my_put_nbr(va_arg(arg, unsigned int));
}

void print_a(va_list arg)
{
    my_putchar('%');
}

void print_p(va_list arg)
{
    uintptr_t p = (uintptr_t)(va_arg(arg, void *));
    int len = sizeof(p) * CHAR_BIT / 4;
    char *str = malloc(sizeof(char) * len + 1);
    int i = 0;

    str[len] = '\0';
    while (i < len) {
        str[i] = char_to_hex((p % 16));
        p = p / 16;
        i++;
    }
    str = my_revstr(str);
    i = 0;
    while (str[i] == '0')
        i++;
    my_putstr("0x");
    my_putstr(&str[i]);
    free(str);
}
