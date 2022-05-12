/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy_animation.c
*/

#include "game.h"
#include "enemy.h"

sfTexture **get_texture(enemy_t *enemy);
sfVector3f get_rect(enemy_t *enemy);

void set_state(enemy_t *enemy, int state)
{
    sfVector3f rect;
    sfTexture **texture;

    if (enemy->state == state)
        return;
    enemy->state = state;
    rect = get_rect(enemy);
    texture = get_texture(enemy);
    sfSprite_setTexture(enemy->sprite, texture[enemy->direction], sfTrue);
    sfSprite_setTextureRect(enemy->sprite, (sfIntRect){0, 0, rect.y, rect.z});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){rect.y / 2, rect.z / 2});
}

void set_direction(enemy_t *enemy, int direction)
{
    sfVector3f rect;
    sfTexture **texture;

    if (enemy->direction == direction)
        return;
    enemy->direction = direction;
    rect = get_rect(enemy);
    texture = get_texture(enemy);
    sfSprite_setTexture(enemy->sprite, texture[enemy->direction], sfTrue);
    sfSprite_setTextureRect(enemy->sprite, (sfIntRect){0, 0, rect.y, rect.z});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){rect.y / 2, rect.z / 2});
}

static int reset_animation(enemy_t *enemy, sfIntRect *rect)
{
    player_t *player = &game()->player;

    srand(time(NULL));
    rect->left = 0;
    if (enemy->state == E_DEATH) {
        kill_enemy(enemy);
        return (1);
    } else if (enemy->state == E_DAMAGE) {
        enemy->set_state(enemy, E_IDLE);
        return (1);
    }
    if (enemy->state == E_ATTACK) {
        player->set_health(player->stats.health
        - enemy->stats.attack - (rand() % player->stats.defense));
        return (0);
    }
    return (0);
}

void animate(enemy_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->clock);
    float seconds = time.microseconds / 100000.0;
    sfIntRect rect = sfSprite_getTextureRect(enemy->sprite);
    sfVector3f rect_data = get_rect(enemy);
    int end = 0;

    if (seconds >= 1.25) {
        if (rect.left == (rect_data.x - 1) * rect_data.y)
            end = reset_animation(enemy, &rect);
        else
            rect.left += rect_data.y;
        if (end == 1)
            return;
        sfSprite_setTextureRect(enemy->sprite, rect);
        sfClock_restart(enemy->clock);
    }
}
