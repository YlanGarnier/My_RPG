/*
** EPITECH PROJECT, 2021
** day7
** File description:
** my_rev_params
*/

#include "my.h"

void my_rev_params(int argc, char **argv)
{
    for (int i = argc - 1; i >= 0; i -= 1) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
}
