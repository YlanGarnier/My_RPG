/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_ui.c
*/

#include "game.h"
#include "player.h"

static void update(void)
{
    update_health_position();
    update_xp_position();
}

static void draw(void)
{
    player_ui_t *ui = &game()->player.ui;
    sfRenderWindow *window = game()->window.sf_window;

    sfRenderWindow_drawRectangleShape(window, ui->health_bar_bg, NULL);
    sfRenderWindow_drawRectangleShape(window, ui->health_bar, NULL);
    sfRenderWindow_drawSprite(window, ui->health_icon, NULL);
    sfRenderWindow_drawRectangleShape(window, ui->xp_bar_bg, NULL);
    sfRenderWindow_drawRectangleShape(window, ui->xp_bar, NULL);
    sfRenderWindow_drawSprite(window, ui->xp_icon, NULL);
}

void initialize_ui(void)
{
    player_ui_t *ui = &game()->player.ui;

    ui->update = update;
    ui->draw = draw;
    initialize_health_bar();
    initialize_xp_bar();
}
