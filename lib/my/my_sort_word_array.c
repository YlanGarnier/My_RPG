/*
** EPITECH PROJECT, 2021
** day10
** File description:
** my_sort_word_array
*/

#include "my.h"
#include <stddef.h>

static void sort(char **array, int size, int i, int j)
{
    int index = 0;
    if ((i + j) > (size - 1))
        index = (i + j) - size;
    else
        index = i + j;
    if (array[i][0] < array[index][0]) {
        char *temp1 = array[i];
        char *temp2 = array[index];
        array[i] = temp2;
        array[index] = temp1;
    }
}

int my_sort_word_array(char **tab)
{
    int size = 0;
    for (int i = 0; tab[i] != NULL; i += 1)
        size += 1;
    for (int i = 0; i < size; i += 1)
        for (int j = 0; j < size; j += 1)
            sort(tab, size, i, j);
    return (0);
}
