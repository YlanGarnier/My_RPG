/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_health.c
*/

#include "game.h"
#include "player.h"

static void update_health_bar(player_t *player)
{
    player_ui_t *ui = &player->ui;

    sfRectangleShape_setSize(ui->health_bar,
    (sfVector2f){((float)player->stats.health /
    (float)player->stats.max_health) * 200.0f, 15.0f});
    sfRectangleShape_setSize(ui->health_bar_bg,
    (sfVector2f){202.0f, 16.0f});
}

static void set_health(int health)
{
    if (health > game()->player.stats.max_health) {
        game()->player.set_health(game()->player.stats.max_health);
        return;
    }
    if (health <= 0)
        health = 0;
    game()->player.stats.health = health;
    update_health_bar(&game()->player);
}

void update_health_position(void)
{
    window_t *window = &game()->window;
    player_t *player = &game()->player;
    player_ui_t *ui = &player->ui;
    sfVector2f pos = {player->position.x - (window->width / 2) + 62.5,
    player->position.y - (game()->window.height / 2) + 24.5};
    sfVector2f icon_pos = {player->position.x - (window->width / 2) + 50,
    player->position.y - (game()->window.height / 2) + 10};

    sfRectangleShape_setPosition(ui->health_bar, pos);
    sfRectangleShape_setPosition(ui->health_bar_bg, pos);
    icon_pos.x -= 15;
    icon_pos.y += 25;
    sfSprite_setPosition(ui->health_icon, icon_pos);
}

void initialize_health_bar(void)
{
    player_t *player = &game()->player;
    player_ui_t *ui = &game()->player.ui;
    sfTexture *heart = sfTexture_createFromFile("assets/player/heart.png",
    NULL);

    player->set_health = set_health;
    ui->health_bar = sfRectangleShape_create();
    ui->health_bar_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(ui->health_bar, sfRed);
    sfRectangleShape_setFillColor(ui->health_bar_bg, sfBlack);
    sfRectangleShape_setSize(ui->health_bar,
    (sfVector2f){((float)player->stats.health /
    (float)player->stats.max_health) * 200.0f, 15.0f});
    sfRectangleShape_setSize(ui->health_bar_bg,
    (sfVector2f){202.0f, 16.0f});
    ui->health_icon = sfSprite_create();
    sfSprite_setTexture(ui->health_icon, heart, sfTrue);
    sfSprite_setOrigin(ui->health_icon, (sfVector2f){127, 127});
    sfSprite_setScale(ui->health_icon, (sfVector2f){0.125, 0.125});
}
