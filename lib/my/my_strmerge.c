/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** write a function that concatenates two strings
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *);

char *my_strmerge(char const *str1, char const *str2)
{
    int str1_size = my_strlen(str1);
    int str2_size = my_strlen(str2);
    int size = str1_size + str2_size;
    char *dest = malloc(sizeof(char) * (size + 1));

    dest[size] = '\0';
    for (int i = 0, j = 0, turn = 1; i < size; i++, j++) {
        if (i == str1_size) {
            turn = 2;
            j = 0;
        }
        if (turn == 1)
            dest[i] = str1[j];
        if (turn == 2)
            dest[i] = str2[j];
    }
    return dest;
}
