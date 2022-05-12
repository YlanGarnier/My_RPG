/*
** EPITECH PROJECT, 2022
** chatbox
** File description:
** chatbox rpg
*/

#include <stdlib.h>
#include "game.h"

int get_textnlen(char *str, int n)
{
    int len = 0;

    for (int i = 0; i < n && str[i] != '\0'; ++i)
        if (str[i] != '\\' || str[i + 1] != 'n')
            ++len;
    return len;
}

int fill_str(char *dest, char *src, int len)
{
    for (int i = 0, j = 0; i < len; ++i, ++j) {
        if (src[j] == '\\' && src[j + 1] == 'n') {
            dest[i] = '\n';
            ++j;
        } else
            dest[i] = src[j];
    }
    return 0;
}

void update_pos(chatbox_t *chatbox, window_t *window, sfVector2f player_pos)
{
    sfVector2f box_pos;
    sfVector2f box_size = sfRectangleShape_getSize(chatbox->box);

    sfRectangleShape_setPosition(chatbox->box, (sfVector2f) {player_pos.x
    - (box_size.x / 2), player_pos.y + (window->height / 2 -
    box_size.y - 30)});
    box_pos = sfRectangleShape_getPosition(chatbox->box);
    if (chatbox->choice == 0)
        sfRectangleShape_setPosition(chatbox->arrow, (sfVector2f)
        {box_pos.x + 35, box_pos.y + 36});
    else
        sfRectangleShape_setPosition(chatbox->arrow, (sfVector2f)
        {box_pos.x + 35, box_pos.y + 65});
    sfText_setPosition(chatbox->text, (sfVector2f)
    {box_pos.x + 75, box_pos.y + 26});
    sfText_setPosition(chatbox->instruction, (sfVector2f)
    {box_pos.x + 475, box_pos.y + 105});
}
