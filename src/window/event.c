/*
** EPITECH PROJECT, 2022
** event.c
** File description:
** event
*/

#include "../../include/window.h"
#include "../../include/game.h"

void check_close(sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game()->window.sf_window);
}
