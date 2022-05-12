/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy_utils.c
*/

#include "game.h"
#include "enemy.h"

sfTexture **get_texture(enemy_t *enemy)
{
    enemy_t *enemies = game()->enemies;
    int state = enemy->state;
    int type = enemy->type;

    if (state == E_ATTACK)
        return (enemies[type].textures.attack);
    if (state == E_DAMAGE)
        return (enemies[type].textures.damage);
    if (state == E_DEATH)
        return (enemies[type].textures.death);
    if (state == E_MOVEMENT)
        return (enemies[type].textures.movement);
    if (state == E_IDLE)
        return (enemies[type].textures.idle);
    return (NULL);
}

sfVector3f get_rect(enemy_t *enemy)
{
    int type = enemy->type;
    int state = enemy->state;
    enemy_t *enemies = game()->enemies;

    if (state == E_ATTACK)
        return (enemies[type].rect.attack[enemy->direction]);
    if (state == E_DAMAGE)
        return (enemies[type].rect.damage[enemy->direction]);
    if (state == E_DEATH)
        return (enemies[type].rect.death[enemy->direction]);
    if (state == E_MOVEMENT)
        return (enemies[type].rect.movement[enemy->direction]);
    if (state == E_IDLE)
        return (enemies[type].rect.idle[enemy->direction]);
    return ((sfVector3f){-1, -1, -1});
}

int get_last_id(void)
{
    int i = 0;

    for (; game()->entities.enemies[i] != NULL; i++);
    return (game()->entities.enemies[i - 1]->id);
}
