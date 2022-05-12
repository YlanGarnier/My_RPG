/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** entities_utils.c
*/

#include "game.h"
#include "entities.h"

static int is_equal(enemy_t *enemy1, enemy_t *enemy2)
{
    if (enemy1->id == enemy2->id)
        return (1);
    return (0);
}

int get_index(enemy_t **array, enemy_t *current)
{
    for (int i = 0; array[i] != NULL; i++)
        if (is_equal(array[i], current))
            return (i);
    return (-1);
}

int get_size(enemy_t **array)
{
    int size = 0;

    for (; array[size] != NULL; size++);
    return (size);
}

int count_enemy(void)
{
    int i = 0;

    for (; game()->entities.enemies[i] != NULL; i++);
    return (i - 1);
}
