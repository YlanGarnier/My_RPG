/*
** EPITECH PROJECT, 2022
** menu_in_game
** File description:
** menu_in_game
*/

#include "save.h"
#include "game.h"

void check_button(int nb)
{
    if (nb == 0)
        game()->state = 0;
    if (nb == 1)
        sfRenderWindow_close(game()->window.sf_window);
    for (int i = 2; i < 5; ++i) {
        if (nb == 2)
            save_game("saves/save1.save");
        if (nb == 3)
            save_game("saves/save2.save");
        if (nb == 4)
            save_game("saves/save3.save");
    }
}

void menu_ig_event(sfEvent event)
{
    button_t *button = game()->menu_ig.button;
    window_t *window = &game()->window;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->sf_window);
    sfVector2f shape_pos;
    sfVector2f size;

    if (game()->state != 2)
        return;
    for (int i = 0; i < 5; ++i) {
        shape_pos = button[i].pos;
        size = button[i].size;
        if (mouse_pos.x >= shape_pos.x && mouse_pos.x <= shape_pos.x + size.x
        && mouse_pos.y >= shape_pos.y && mouse_pos.y <= shape_pos.y + size.y)
            check_button(i);
    }
}
