/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_animation.c
*/

#include "game.h"
#include "player.h"

static void rotate_sword(player_t *player)
{
    sfVector2f pos = player->position;

    if (game()->player.direction == UP) {
        sfSprite_setRotation(game()->player.sword_sprite, 90);
        sfSprite_setPosition(game()->player.sword_sprite,
        (sfVector2f) {pos.x - 10, pos.y + 10});
    } if (game()->player.direction == DOWN) {
        sfSprite_setRotation(game()->player.sword_sprite, -90);
        sfSprite_setPosition(game()->player.sword_sprite,
        (sfVector2f) {pos.x + 10, pos.y});
    } if (game()->player.direction == LEFT) {
        sfSprite_setRotation(game()->player.sword_sprite, 0);
        sfSprite_setPosition(game()->player.sword_sprite,
        (sfVector2f) {pos.x, pos.y + 10});
    } if (game()->player.direction == RIGHT) {
        sfSprite_setRotation(game()->player.sword_sprite, 180);
        sfSprite_setPosition(game()->player.sword_sprite,
        (sfVector2f) {pos.x, pos.y});
    }
}

void animate_sword(void)
{
    sfTime time = sfClock_getElapsedTime(game()->player.attack_clock);
    float seconds = time.microseconds / 1000000.0;

    for (int i = 0; i < 22; i++)
        if (seconds >= (i - 1) * 0.01 && seconds < i * 0.01)
            sfSprite_setTexture(game()->player.sword_sprite,
            game()->player.sprites.attack_sword[i], sfTrue);
    if (seconds >= 0.22)
        game()->player.attacking = 0;
    rotate_sword(&game()->player);
}

static void animate(void)
{
    sfTime time = sfClock_getElapsedTime(game()->player.animation_clock);
    float seconds = time.microseconds / 1000000.0;

    for (int i = 0; i < 8; i++)
        if (seconds >= (i - 1) * 0.0625 && seconds < i * 0.0625)
            sfSprite_setTexture(game()->player.sprite,
            choose_texture(i), sfTrue);
    if (seconds >= 0.5)
        sfClock_restart(game()->player.animation_clock);
}

void initialize_animation(void)
{
    game()->player.animate = animate;
}
