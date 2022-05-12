/*
** EPITECH PROJECT, 2022
** menu_event.c
** File description:
** menu event
*/

#include "game.h"
#include "save.h"
#include "menu.h"

static void more_events(int i)
{
    if (i == 11) {
            load_save("saves/save3.save");
            start_game();
        }
        if (i == 12)
            reduce_fps(game()->menu->background[14]);
        if (i == 13)
            increase_fps(game()->menu->background[14]);
        if (i == 15)
            reduce_sound(game()->menu->background[17]);
        if (i == 16)
            increase_sound(game()->menu->background[17]);
}

void check_event(int state, int i)
{
    if (state == 1) {
        if (i == 1)
            start_game();
        if (i == 4)
            sfRenderWindow_close(game()->window.sf_window);
        if (i == 9) {
            load_save("saves/save1.save");
            start_game();
        }
        if (i == 10) {
            load_save("saves/save2.save");
            start_game();
        }
        more_events(i);
    }
}

bool check_click(int state)
{
    if (state == 1)
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return true;
    return false;
}

bool check_idle(sfRectangleShape *rect)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game()->window.sf_window);
    sfVector2f top = sfRectangleShape_getPosition(rect);
    sfVector2f size = sfRectangleShape_getSize(rect);

    if (pos.x > top.x && pos.x < (top.x + size.x) && pos.y >
    top.y && pos.y < (top.y + size.y))
        return true;
    return false;
}

void menu_event(void)
{
    window_t *window = &game()->window;
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->sf_window, &event)) {
        menu_update();
        check_close(event);
    }
}
