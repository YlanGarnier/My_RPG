/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_movement.c
*/

#include "game.h"
#include "player.h"

static void update_direction(player_t *player)
{
    float direction[4] = {180, -90, 90, 0.0};
    sfVector2f pos = player->position;
    sfVector2f next_pos = {pos.x + player->velocity.x,
    pos.y + player->velocity.y};
    sfVector2f dir = {next_pos.x - pos.x, pos.y - next_pos.y};
    float angle = atan2(dir.x, dir.y) * (180 / PI);

    if (player->attacking)
        return;
    if (angle >= -45.0f && angle <= 45.0f)
        player->direction = UP;
    if (angle > 45.0f && angle <= 135.0f)
        player->direction = RIGHT;
    if (angle > 135.0f && angle >= -135.0f)
        player->direction = DOWN;
    if (angle > -135.0f && angle <= -45.0f)
        player->direction = LEFT;
    sfRectangleShape_setRotation(player->attack_box,
    direction[player->direction]);
}

static void move(void)
{
    player_t *player = &game()->player;
    chatbox_t *chatbox = &game()->chatbox;

    if (player->velocity.x == 0 && player->velocity.y == 0) {
        player->state = IDLE;
        sfSprite_setTexture(game()->player.sprite, choose_texture(0), sfTrue);
        return;
    }
    chatbox->chat_index = check_pnj();
    update_direction(player);
    sfSprite_move(player->sprite, player->velocity);
    player->animate();
}

void initialize_movement(void)
{
    game()->player.move = move;
}
