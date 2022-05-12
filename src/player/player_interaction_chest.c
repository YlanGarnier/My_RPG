/*
** EPITECH PROJECT, 2022
** player_interactions.c
** File description:
** player interactions
*/

#include "game.h"
#include "player.h"
#include "map.h"

static bool goldenchest_near_player(void)
{
    if (check_horizontal(TILE_RIGHT, RIGHT, GOLDEN))
        return true;
    if (check_horizontal(TILE_LEFT, LEFT, GOLDEN))
        return true;
    if (check_vertical(TILE_UP, UP, GOLDEN))
        return true;
    if (check_vertical(TILE_DOWN, DOWN, GOLDEN))
        return true;
    return false;
}

static bool chest_near_player(void)
{
    if (check_horizontal(TILE_RIGHT, RIGHT, CHEST))
        return true;
    if (check_horizontal(TILE_LEFT, LEFT, CHEST))
        return true;
    if (check_vertical(TILE_UP, UP, CHEST))
        return true;
    if (check_vertical(TILE_DOWN, DOWN, CHEST))
        return true;
    return false;
}

static void check_goldenchests(void)
{
    player_t *player = &game()->player;

    if (goldenchest_near_player()) {
        if (player->inventory.empty_slot > 0) {
            add_item(KEY);
            player->inventory.open = 1;
            sfSound_play(game()->sounds[2].sound);
        }
        return;
    }
}

void check_chests(void)
{
    item_t *items = game()->items;
    player_t *player = &game()->player;
    int count = 0;
    int it;

    for (; items[count].id != -1; count++);
    srand(time(NULL));
    if (chest_near_player()) {
        if (player->inventory.empty_slot > 0) {
            it = rand() % count;
            it = it == KEY ? it - 1 : it;
            add_item(it);
            player->inventory.open = 1;
        }
    }
    check_goldenchests();
}
