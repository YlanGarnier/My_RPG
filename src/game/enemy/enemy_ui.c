/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy_ui.c
*/

#include "game.h"
#include "enemy.h"

static void update(enemy_t *enemy)
{
    sfVector2f health_pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f text_pos;

    health_pos.y -= 30;
    text_pos = health_pos;
    text_pos.x -= 25.0 * 1.05;
    text_pos.y -= 17;
    sfRectangleShape_setPosition(enemy->ui.health_bar, health_pos);
    sfRectangleShape_setPosition(enemy->ui.health_bar_bg, health_pos);
    sfText_setPosition(enemy->ui.level, text_pos);
}

static void draw(enemy_t *enemy)
{
    sfRenderWindow *window = game()->window.sf_window;

    sfRenderWindow_drawRectangleShape(window, enemy->ui.health_bar_bg, NULL);
    sfRenderWindow_drawRectangleShape(window, enemy->ui.health_bar, NULL);
    sfRenderWindow_drawText(window, enemy->ui.level, NULL);
}

static void initialize_enemy_health_bar(enemy_t *enemy)
{
    enemy->ui.health_bar = sfRectangleShape_create();
    sfRectangleShape_setFillColor(enemy->ui.health_bar, sfRed);
    sfRectangleShape_setSize(enemy->ui.health_bar, (sfVector2f){50.0, 6.0});
    sfRectangleShape_setOrigin(enemy->ui.health_bar, (sfVector2f){25.0, 3.0});
    enemy->ui.health_bar_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(enemy->ui.health_bar_bg, sfBlack);
    sfRectangleShape_setSize(enemy->ui.health_bar_bg,
    (sfVector2f){50.0 * 1.05, 6.0 * 1.2});
    sfRectangleShape_setOrigin(enemy->ui.health_bar_bg,
    (sfVector2f){25.0 * 1.05, 3.0 * 1.2});
}

static void initialize_enemy_text(enemy_t *enemy)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/rpg.ttf");
    enemy->ui.level = sfText_create();
    sfText_setFont(enemy->ui.level, font);
    sfText_setCharacterSize(enemy->ui.level, 10);
    sfText_setColor(enemy->ui.level, sfWhite);
    sfText_setOutlineColor(enemy->ui.level, sfBlack);
    sfText_setOutlineThickness(enemy->ui.level, 0.5);
    sfText_setString(enemy->ui.level, cat_text("Lvl ",
    my_itoa(enemy->stats.level)));
}

void initialize_enemy_ui(enemy_t *enemy)
{
    enemy->ui.update = update;
    enemy->ui.draw = draw;
    initialize_enemy_health_bar(enemy);
    initialize_enemy_text(enemy);
}
