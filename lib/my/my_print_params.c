/*
** EPITECH PROJECT, 2021
** day7
** File description:
** my_print_params
*/

#include "my.h"

void my_print_params(int argc, char **argv)
{
    for (int i = 0; i < argc; i += 1) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
}
