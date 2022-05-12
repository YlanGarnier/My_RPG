/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf_wrappers
*/

#include "my.h"
#include <stdlib.h>

void print_i(va_list arg)
{
    my_put_nbr(va_arg(arg, int));
}

void print_s(va_list arg)
{
    my_putstr(va_arg(arg, char *));
}

void print_ss(va_list arg)
{
    char *str = va_arg(arg, char *);
    char octal[] = "000";
    char *converted;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            converted = convert_base(my_itoa(str[i]), "10", "8");
            my_putstr(&octal[my_strlen(converted)]);
            my_putstr(converted);
        } else
            my_putchar(str[i]);
    }
    free(converted);
}

void print_c(va_list arg)
{
    my_putchar(va_arg(arg, int));
}

void print_o(va_list arg)
{
    char *str = my_itoa(va_arg(arg, unsigned int));

    my_putstr(convert_base(str, "10", "8"));
}
