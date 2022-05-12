/*
** EPITECH PROJECT, 2022
** menu_initialize.c
** File description:
** intialize buttons
*/

#include "../../include/menu.h"

buttons_t *initialize_buttons(int buttons_nb)
{
    buttons_t *buttons = malloc(sizeof(buttons_t) * buttons_nb);

    for (int i = 0; i < buttons_nb; i++) {
        buttons[i].texture = texture[i].texture;
        buttons[i].colored = colored[i].colored;
        buttons[i].event = event[i].event;
        buttons[i].pos = position[i].position;
        buttons[i].size = size[i].size;
        buttons[i].color = color[i].colour;
    }
    return buttons;
}
