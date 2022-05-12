/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf.c
*/

#include "my.h"

void print_i(va_list);
void print_s(va_list);
void print_ss(va_list);
void print_c(va_list);
void print_o(va_list);
void print_x(va_list);
void print_xx(va_list);
void print_b(va_list);
void print_u(va_list);
void print_a(va_list);
void print_p(va_list);

const flag_t FLAG_TYPES[] = {
    {'i', &print_i},
    {'d', &print_i},
    {'s', &print_s},
    {'S', &print_ss},
    {'c', &print_c},
    {'o', &print_o},
    {'x', &print_x},
    {'X', &print_xx},
    {'b', &print_b},
    {'u', &print_u},
    {'%', &print_a},
    {'p', &print_p}
};

static void print_flag(char const c, va_list arg)
{
    for (int i = 0; i < 12; i++) {
        if (c == FLAG_TYPES[i].type) {
            FLAG_TYPES[i].func(arg);
            return;
        }
    }
    my_putchar('%');
    my_putchar(c);
}

static void print_formatted_str(const char *format, va_list arg)
{
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            print_flag(format[i + 1], arg);
            i++;
        } else
            my_putchar(format[i]);
    }
}

int my_printf(const char *format, ...)
{
    va_list arg;

    va_start(arg, format);
    print_formatted_str(format, arg);
    va_end(arg);
    return 0;
}
