/*
** EPITECH PROJECT, 2022
** player_position.c
** File description:
** player position events
*/

#include "../../include/game.h"

void update_position(void)
{
    player_t *player = &game()->player;

    player->position = sfSprite_getPosition(player->sprite);
    player->position.x += 5;
    player->position.y += 25;
}

static sfVector2i get_tile(void)
{
    sfVector2f pos_f;
    sfVector2i pos_i;
    float x = game()->player.position.x;
    float y = game()->player.position.y;

    pos_f.x = x / (448 * (20 * ZOOM)) * 448;
    pos_f.y = y / (336 * (20 * ZOOM)) * 336;
    pos_i.x = pos_f.x;
    pos_i.y = pos_f.y;
    return pos_i;
}

static int get_pos(int tile, int mode)
{
    int upper_y;
    int under_y;
    int left_x;
    int right_x;

    if (mode == UP)
        return upper_y = tile * 336 * (20 * ZOOM) / 336 + (20 * ZOOM);
    if (mode == DOWN)
        return under_y = tile * 336 * (20 * ZOOM) / 336;
    if (mode == LEFT)
        return left_x = tile * 448 * (20 * ZOOM) / 448 + (20 * ZOOM);
    if (mode == RIGHT)
        return right_x = tile * 448 * (20 * ZOOM) / 448;
    return 0;
}

bool check_horizontal(int direction, int mode, int col)
{
    sfVector2i tile = get_tile();
    int tile_pos = get_pos(tile.x + direction, mode);
    int player_pos = game()->player.position.x;

    if (game()->map.back_col[tile.y][tile.x + direction] == col)
        if ((tile_pos - player_pos) < (10 * ZOOM))
            return true;
    return false;
}

bool check_vertical(int direction, int mode, int col)
{
    sfVector2i tile = get_tile();
    int tile_pos = get_pos(tile.y + direction, mode);
    int player_pos = game()->player.position.y;

    if (game()->map.back_col[tile.y + direction][tile.x] == col)
        if ((tile_pos - player_pos) < (10 * ZOOM))
            return true;
    return false;
}
