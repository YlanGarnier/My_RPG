/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy_movement.c
*/

#include "game.h"
#include "enemy.h"

static void update_direction(enemy_t *enemy)
{
    sfVector2f enemy_pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f pos = game()->player.position;
    sfVector2f dir = {enemy_pos.x - pos.x, pos.y - enemy_pos.y};
    float angle = atan2(dir.x, dir.y) * (180 / PI);

    if (enemy->state == E_DEATH)
        return;
    if (angle >= -45.0f && angle <= 45.0f)
        enemy->set_direction(enemy, E_DOWN);
    if (angle > 45.0f && angle <= 135.0f)
        enemy->set_direction(enemy, E_LEFT);
    if (angle > 135.0f && angle >= -135.0f)
        enemy->set_direction(enemy, E_UP);
    if (angle > -135.0f && angle <= -45.0f)
        enemy->set_direction(enemy, E_RIGHT);
}

void move(enemy_t *enemy)
{
    update_direction(enemy);
    sfSprite_move(enemy->sprite, enemy->velocity);
}

void pathfind(enemy_t *enemy)
{
    sfVector2f p_pos = game()->player.position;
    sfVector2f e_pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f dir = {p_pos.x - e_pos.x, p_pos.y - e_pos.y};
    float distance = sqrt(dir.x * dir.x + dir.y * dir.y);

    if (enemy->state == E_DEATH || enemy->state == E_DAMAGE)
        return;
    if (distance >= 200.0f) {
        enemy->set_state(enemy, E_IDLE);
        return;
    } else if (distance <= 40.0f) {
        enemy->set_state(enemy, E_ATTACK);
        return;
    }
    enemy->set_state(enemy, E_MOVEMENT);
    dir = (sfVector2f){dir.x / distance, dir.y / distance};
    enemy->velocity.x += dir.x * (enemy->stats.speed * ZOOM) *
        game()->delta_time;
    enemy->velocity.y += dir.y * (enemy->stats.speed * ZOOM) *
        game()->delta_time;
}
