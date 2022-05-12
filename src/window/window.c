/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** window.c
*/

#include "window.h"
#include "game.h"

static void clear(void)
{
    window_t *window = &game()->window;

    sfRenderWindow_clear(window->sf_window, sfBlack);
}

static void update(void)
{
    window_t *window = &game()->window;

    sfRenderWindow_display(window->sf_window);
}

static void destroy(void)
{
    window_t *window = &game()->window;

    sfRenderWindow_destroy(window->sf_window);
}

static sfBool opened(void)
{
    window_t *window = &game()->window;

    return (sfRenderWindow_isOpen(window->sf_window));
}

window_t create_window(char const *name, int width, int height)
{
    window_t window;
    sfVideoMode sf_mode = {width, height, 32};

    window.fps = 60;
    window.width = width;
    window.height = height;
    window.clear = clear;
    window.update = update;
    window.destroy = destroy;
    window.opened = opened;
    window.sf_window = sfRenderWindow_create(sf_mode, name,
    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window.sf_window, window.fps);
    return (window);
}
