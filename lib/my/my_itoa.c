/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_itoa.c
*/

#include "my.h"
#include <stdlib.h>

char *my_itoa(int nb)
{
    char *str;
    int tmp_nb = nb;
    int nb_len = 1;
    int size;

    for (; ABS(tmp_nb) >= 10; nb_len++)
        tmp_nb /= 10;
    size = nb >= 0 ? nb_len + 1 : nb_len + 2;
    str = malloc(sizeof(char) * size);
    str[size - 1] = '\0';
    str[size - 2] = nb >= 0 ? ' ' : '-';
    for (int i = 0; i < nb_len; i++, nb /= 10)
        str[i] = ABS(nb) % 10 + '0';
    return my_revstr(str);
}
