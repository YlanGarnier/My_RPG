/*
** EPITECH PROJECT, 2022
** menu_button.c
** File description:
** buttons
*/

#include "../../include/game.h"

static void arrows_update(int state, sfRectangleShape *rect, sfColor color)
{
    if (state == 1) {
        color.a = 100;
        color.r = 255;
        color.g = 0;
        color.b = 255;
        sfRectangleShape_setFillColor(rect, color);
    } else if (state == 0) {
        color.a = 255;
        color.r = 255;
        color.g = 255;
        color.b = 255;
        sfRectangleShape_setFillColor(rect, color);
    }
}

static void save_update(int state, sfRectangleShape *rect, sfColor color)
{
    if (state == 1) {
        color.a = 255;
        color.r = 255;
        color.g = 255;
        color.b = 255;
        sfRectangleShape_setFillColor(rect, color);
    } else if (state == 0) {
        color.a = 200;
        color.r = 0;
        color.g = 0;
        color.b = 0;
        sfRectangleShape_setFillColor(rect, color);
    }
}

static void veil_update(int state, sfRectangleShape *rect, sfColor color)
{
    if (state == 1) {
        color.a = 20;
        sfRectangleShape_setFillColor(rect, color);
    } else if (state == 0) {
        color.a = 220;
        sfRectangleShape_setFillColor(rect, color);
    }
}

void button_update(int state, int i)
{
    sfRectangleShape *rect = game()->menu->background[i];
    sfColor color = sfRectangleShape_getFillColor(rect);

    if (i < 5)
        veil_update(state, rect, color);
    if (i > 8 && i <= 11)
        save_update(state, rect, color);
    if (i >= 12 && i <= 17)
        arrows_update(state, rect, color);
}
