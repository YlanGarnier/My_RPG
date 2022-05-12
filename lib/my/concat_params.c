/*
** EPITECH PROJECT, 2021
** day8
** File description:
** concat_params
*/

#include "my.h"
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int total_len = 0;
    char *concated_params;
    for (int i = 0; i < argc; i += 1)
        total_len += my_strlen(argv[i]) + 1;
    concated_params = malloc(sizeof(char) * total_len);
    for (int i = 0; argv[i] != NULL; i += 1) {
        my_strcat(concated_params, argv[i]);
        if (i < argc - 1)
            my_strcat(concated_params, "\n");
    }
    return concated_params;
}
