/*
** EPITECH PROJECT, 2022
** my_arraylen
** File description:
** return size of an array
*/

#include <stddef.h>

int my_arraylen(char **array)
{
    int size = 0;

    while (array[size] != NULL)
        size++;
    return size;
}
