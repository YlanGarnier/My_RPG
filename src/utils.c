/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** utils.c
*/

#include "game.h"

char *cat_text(char *base, const char *to_add)
{
    int len = my_strlen(base) + my_strlen(to_add) + 1;
    char *text = malloc(sizeof(char) * len);

    my_strcpy(text, base);
    my_strcat(text, to_add);
    return (text);
}

float get_delta_time(void)
{
    float delta_time = sfClock_getElapsedTime(game()->clock).microseconds
    / 1000000.0;

    sfClock_restart(game()->clock);
    return (delta_time);
}
