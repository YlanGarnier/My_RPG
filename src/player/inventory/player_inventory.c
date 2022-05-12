/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_inventory.c
*/

#include "game.h"
#include "player.h"

static void update(void)
{
    player_t *player = &game()->player;
    inventory_t *inventory = &player->inventory;
    sfVector2f pos = {player->position.x + 300, player->position.y};
    sfVector2f slot_pos;

    sfSprite_setPosition(inventory->sprite, pos);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            slot_pos = (sfVector2f){player->position.x + 141.5 + (j * 50),
            player->position.y - 73 + (i * 50)};
            sfRectangleShape_setPosition(inventory->slots[i][j].ui, slot_pos);
        }
    }
}

static void draw(void)
{
    sfRenderWindow *window = game()->window.sf_window;
    inventory_t *inventory = &game()->player.inventory;

    if (!inventory->open)
        return;
    sfRenderWindow_drawSprite(window, inventory->sprite, NULL);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            inventory->slots[i][j].update(&inventory->slots[i][j]);
            inventory->slots[i][j].draw(&inventory->slots[i][j]);
        }
    }
}

static void initialize_sprite(void)
{
    inventory_t *inventory = &game()->player.inventory;
    sfTexture *inv_texture =
    sfTexture_createFromFile("assets/player/inventory.png", NULL);
    sfVector2f inv_scale = {0.6, 0.6};
    sfVector2f inv_origin = {340.0, 264.0};

    inventory->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->sprite, inv_texture, sfTrue);
    sfSprite_setScale(inventory->sprite, inv_scale);
    sfSprite_setOrigin(inventory->sprite, inv_origin);
}

void initialize_inventory(void)
{
    inventory_t *inventory = &game()->player.inventory;

    initialize_sprite();
    inventory->slot_count = 35;
    inventory->empty_slot = 35;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
            initialize_slot(j, i);
    inventory->open = 0;
    inventory->update = update;
    inventory->draw = draw;
}
