/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_inventory.c
*/

#include "game.h"
#include "player.h"

void use_item(slot_t *slot, item_t *item)
{
    player_t *player = &game()->player;

    if (slot->empty)
        return;
    if (item->stat == NULL)
        return;
    if (item->stat == &player->stats.health) {
        player->set_health(player->stats.health + item->add_value);
        remove_item(slot);
        return;
    }
    *(item->stat) += item->add_value;
    remove_item(slot);
}

void add_item(int id)
{
    item_t *item;
    slot_t *slot;

    if (id == -1) return;
    item = malloc(sizeof(struct item));
    item->id = game()->items[id].id;
    item->name = game()->items[id].name;
    item->description = game()->items[id].description;
    item->sprite = game()->items[id].sprite;
    item->stat = game()->items[id].stat;
    item->add_value = game()->items[id].add_value;
    slot = find_empty_slot();
    slot->item = item;
    slot->item_sprite = sfSprite_copy(item->sprite);
    sfSprite_setPosition(slot->item_sprite,
    sfRectangleShape_getPosition(slot->ui));
    sfSprite_setScale(slot->item_sprite, (sfVector2f){1.5, 1.5});
    slot->empty = 0;
    game()->player.inventory.empty_slot -= 1;
}

void remove_item(slot_t *slot)
{
    if (slot->empty)
        return;
    slot->item = NULL;
    slot->item_sprite = NULL;
    slot->empty = 1;
    game()->player.inventory.empty_slot += 1;
}
