/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_hitbox.c
*/

#include "game.h"
#include "player.h"

void initialize_hitbox(void)
{
    player_t *player = &game()->player;

    player->attack_box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(player->attack_box,
    (sfColor){255, 0, 0, 100});
    sfRectangleShape_setSize(player->attack_box, (sfVector2f){10, 45});
    sfRectangleShape_setOrigin(player->attack_box, (sfVector2f){5, 45});
}
