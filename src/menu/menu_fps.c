/*
** EPITECH PROJECT, 2022
** menu_fps.c
** File description:
** set fps
*/

#include "game.h"
#include "menu.h"

void start_game(void)
{
    sfMusic_stop(game()->sounds[0].music);
    sfMusic_play(game()->sounds[1].music);
    game()->state = 1;
}

void reduce_fps(sfRectangleShape *rect)
{
    sfIntRect font = sfRectangleShape_getTextureRect(rect);
    unsigned int fps = game()->window.fps;

    if (fps > 30) {
        font.top = font.top - 130;
        fps = fps / 2;
        game()->window.fps = fps;
        sfRenderWindow_setFramerateLimit(game()->window.sf_window, fps);
        sfRectangleShape_setTextureRect(rect, font);
    }
}

void increase_fps(sfRectangleShape *rect)
{
    sfIntRect font = sfRectangleShape_getTextureRect(rect);
    unsigned int fps = game()->window.fps;

    if (fps < 120) {
        font.top = font.top + 130;
        fps = fps * 2;
        game()->window.fps = fps;
        sfRenderWindow_setFramerateLimit(game()->window.sf_window, fps);
        sfRectangleShape_setTextureRect(rect, font);
    }
}
