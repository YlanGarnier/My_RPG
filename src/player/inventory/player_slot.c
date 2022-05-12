/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_inventory.c
*/

#include "game.h"
#include "player.h"

static void update(slot_t *slot)
{
    sfRenderWindow *window = game()->window.sf_window;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect slot_rect = sfRectangleShape_getGlobalBounds(slot->ui);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game()->window.sf_window,
    mouse_pos, game()->player.camera.view);

    if (sfFloatRect_contains(&slot_rect, pos.x, pos.y)) {
        sfRectangleShape_setFillColor(slot->ui, (sfColor){255, 255, 255, 100});
        if (sfKeyboard_isKeyPressed(sfKeyX))
            remove_item(slot);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            use_item(slot, slot->item);
    }
    if (!sfFloatRect_contains(&slot_rect, pos.x, pos.y))
        sfRectangleShape_setFillColor(slot->ui, (sfColor){255, 255, 255, 0});
    if (!slot->empty) {
        sfSprite_setPosition(slot->item_sprite,
        sfRectangleShape_getPosition(slot->ui));
    }
}

static void draw(slot_t *slot)
{
    sfRenderWindow *window = game()->window.sf_window;

    sfRenderWindow_drawRectangleShape(window, slot->ui, NULL);
    if (!slot->empty)
        sfRenderWindow_drawSprite(window, slot->item_sprite, NULL);
}

slot_t *find_empty_slot(void)
{
    inventory_t *inventory = &game()->player.inventory;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
            if (inventory->slots[i][j].empty)
                return (&inventory->slots[i][j]);
    return (NULL);
}

static void initialize_pos(slot_t *slot)
{
    int x = slot->x;
    int y = slot->y;
    sfVector2f player_pos = game()->player.position;
    sfVector2f slot_pos = (sfVector2f){player_pos.x + 141.5 + (x * 50),
    player_pos.y - 73 + (y * 50)};

    sfRectangleShape_setPosition(slot->ui, slot_pos);
}

void initialize_slot(int x, int y)
{
    inventory_t *inventory = &game()->player.inventory;
    slot_t *slot = &inventory->slots[y][x];
    sfVector2f slot_size = {75.0, 75.0};
    sfVector2f slot_origin = {37.5, 37.5};
    sfVector2f slot_scale = {0.6, 0.6};

    slot->y = y;
    slot->x = x;
    slot->empty = 1;
    slot->item = NULL;
    slot->item_sprite = NULL;
    slot->ui = sfRectangleShape_create();
    slot->update = update;
    slot->draw = draw;
    sfRectangleShape_setSize(slot->ui, slot_size);
    sfRectangleShape_setOrigin(slot->ui, slot_origin);
    sfRectangleShape_setFillColor(slot->ui, (sfColor){255, 255, 255, 0});
    sfRectangleShape_setScale(slot->ui, slot_scale);
    initialize_pos(slot);
}
