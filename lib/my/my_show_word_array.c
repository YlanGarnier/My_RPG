/*
** EPITECH PROJECT, 2021
** day8
** File description:
** my_show_word_array
*/

#include "my.h"
#include <stdlib.h>

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        my_printf("%s\n", tab[i]);
    return (0);
}
