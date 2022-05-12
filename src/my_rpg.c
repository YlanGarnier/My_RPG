/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** main.c
*/

#include "menu.h"
#include "game.h"
#include "save.h"
#include "window.h"

game_t *game(void)
{
    static game_t game;
    return (&game);
}

static void scene(void)
{
    scene_t scenes[] = {
        {MENU, game()->menu_update },
        {GAME, game()->update },
        {MENU_IG, game()->update }
    };
    unsigned long int scenes_nb = sizeof(scenes) / sizeof(scene_t);
    for (unsigned long int i = 0; i < scenes_nb; i++)
        if (scenes[i].state == game()->state)
            scenes[i].ptr();
}

int main(void)
{
    window_t *window = &game()->window;

    initialize_game();
    while (window->opened())
        scene();
    window->destroy();
    game()->destroy();
    return (0);
}
