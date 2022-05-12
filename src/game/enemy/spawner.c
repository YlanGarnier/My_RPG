/*
** EPITECH PROJECT, 2022
** spawner.c
** File description:
** spawner
*/

#include "game.h"
#include "my.h"
#include "enemy.h"

void spawner(void)
{
    char *file = my_readfile("enemies/spawn.config");
    char **enemies = my_str_to_word_array(file, '\n');
    char **enemy;
    float x = 0;
    float y = 0;

    for (int i = 0; i < my_arraylen(enemies); i++) {
        enemy = my_str_to_word_array(enemies[i], ':');
        x = (float)my_getnbr(enemy[1]);
        y = (float)my_getnbr(enemy[2]);
        spawn_enemy(my_getnbr(enemy[0]), (sfVector2f){x * ZOOM, y * ZOOM});
        my_free_array(enemy);
    }
}
