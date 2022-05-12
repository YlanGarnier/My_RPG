/*
** EPITECH PROJECT, 2022
** player_collisions.c
** File description:
** collisions
*/

#include "player.h"
#include "map.h"
#include "game.h"

bool player_upper_col(void)
{
    if (game()->chatbox.chat_index >= 0)
        return false;
    if (check_vertical(TILE_UP, UP, COLLI))
        return false;
    if (check_vertical(TILE_UP, UP, CHEST))
        return false;
    if (check_vertical(TILE_UP, UP, GOLDEN))
        return false;
    if (check_vertical(TILE_UP, UP, DUNG))
        return false;
    if (check_vertical(TILE_UP, UP, PNJ))
        return false;
    return true;
}

bool player_under_col(void)
{
    if (game()->chatbox.chat_index >= 0)
        return false;
    if (check_vertical(TILE_DOWN, DOWN, COLLI))
        return false;
    if (check_vertical(TILE_DOWN, DOWN, CHEST))
        return false;
    if (check_vertical(TILE_DOWN, DOWN, GOLDEN))
        return false;
    if (check_vertical(TILE_DOWN, DOWN, DUNG))
        return false;
    if (check_vertical(TILE_DOWN, DOWN, PNJ))
        return false;
    return true;
}

bool player_right_col(void)
{
    if (game()->chatbox.chat_index >= 0)
        return false;
    if (check_horizontal(TILE_RIGHT, RIGHT, COLLI))
        return false;
    if (check_horizontal(TILE_RIGHT, RIGHT, CHEST))
        return false;
    if (check_horizontal(TILE_RIGHT, RIGHT, GOLDEN))
        return false;
    if (check_horizontal(TILE_RIGHT, RIGHT, DUNG))
        return false;
    if (check_horizontal(TILE_RIGHT, RIGHT, PNJ))
        return false;
    return true;
}

bool player_left_col(void)
{
    if (game()->chatbox.chat_index >= 0)
        return false;
    if (check_horizontal(TILE_LEFT, LEFT, COLLI))
        return false;
    if (check_horizontal(TILE_LEFT, LEFT, CHEST))
        return false;
    if (check_horizontal(TILE_LEFT, LEFT, GOLDEN))
        return false;
    if (check_horizontal(TILE_LEFT, LEFT, DUNG))
        return false;
    if (check_horizontal(TILE_LEFT, LEFT, PNJ))
        return false;
    return true;
}
