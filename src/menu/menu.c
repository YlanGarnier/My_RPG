/*
** EPITECH PROJECT, 2022
** menu.c
** File description:
** menu
*/

#include "game.h"
#include "window.h"

sfRectangleShape **initialize_background(void);

static void update(void)
{
    window_t *window = &game()->window;

    menu_event();
    window->clear();
    game()->menu->draw();
    window->update();
}

static void draw(void)
{
    for (int i = 0; i < game()->menu->buttons_nb; i++)
        sfRenderWindow_drawRectangleShape(game()->window.sf_window,
        game()->menu->background[i], NULL);
}

void initialize_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    game()->menu = menu;
    game()->menu->background = initialize_background();
    game()->menu_update = update;
    game()->menu->draw = draw;
}
