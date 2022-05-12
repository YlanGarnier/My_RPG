/*
** EPITECH PROJECT, 2022
** player_png_interactions.c
** File description:
** png things
*/

#include "game.h"
#include "player.h"

static bool pnj_near_player(int pnj)
{
    if (check_horizontal(TILE_RIGHT, RIGHT, pnj))
        return true;
    if (check_horizontal(TILE_LEFT, LEFT, pnj))
        return true;
    if (check_vertical(TILE_UP, UP, pnj))
        return true;
    if (check_vertical(TILE_DOWN, DOWN, pnj))
        return true;
    return false;
}

int check_pnj(void)
{
    if (pnj_near_player(PNJ))
        return game()->chatbox.next_chat_index;
    return -1;
}
