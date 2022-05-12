/*
** EPITECH PROJECT, 2022
** player_dungeon_interaction.c
** File description:
** dungeons things
*/

#include "player.h"
#include "map.h"

static bool dungeon_near_player(void)
{
    if (check_vertical(TILE_UP, UP, DUNG))
        return true;
    return false;
}

void check_dungeon(void)
{
    if (dungeon_near_player())
        return;
}
