/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_xp.c
*/

#include "game.h"
#include "player.h"

static void update_xp_bar(player_t *player)
{
    player_ui_t *ui = &player->ui;

    sfRectangleShape_setSize(ui->xp_bar,
    (sfVector2f){((float)player->stats.xp /
    (float)player->stats.max_xp) * 200.0f, 15.0f});
    sfRectangleShape_setSize(ui->xp_bar_bg,
    (sfVector2f){202.0f, 16.0f});
}

static void set_xp(int xp)
{
    player_t *player = &game()->player;

    if (xp >= player->stats.max_xp) {
        xp = 0;
        player->set_point(player->stats.stats_point + 1);
        player->stats.max_xp += 10;
        player->stats.level += 1;
    }
    game()->player.stats.xp = xp;
    update_xp_bar(&game()->player);
}

void update_xp_position(void)
{
    window_t *window = &game()->window;
    player_t *player = &game()->player;
    player_ui_t *ui = &player->ui;
    sfVector2f pos = {player->position.x - (window->width / 2) + 62.5,
    player->position.y - (game()->window.height / 2) + 68.5};
    sfVector2f icon_pos = {player->position.x - (window->width / 2) + 50,
    player->position.y - (game()->window.height / 2) + 50};

    sfRectangleShape_setPosition(ui->xp_bar, pos);
    sfRectangleShape_setPosition(ui->xp_bar_bg, pos);
    icon_pos.x -= 15;
    icon_pos.y += 25;
    sfSprite_setPosition(ui->xp_icon, icon_pos);
}

void initialize_xp_bar(void)
{
    player_t *player = &game()->player;
    player_ui_t *ui = &game()->player.ui;
    sfTexture *xp = sfTexture_createFromFile("assets/player/xp.png", NULL);

    player->set_xp = set_xp;
    ui->xp_bar = sfRectangleShape_create();
    ui->xp_bar_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(ui->xp_bar, sfYellow);
    sfRectangleShape_setFillColor(ui->xp_bar_bg, sfBlack);
    sfRectangleShape_setSize(ui->xp_bar,
    (sfVector2f){((float)player->stats.xp /
    (float)player->stats.max_xp) * 200.0f, 15.0f});
    sfRectangleShape_setSize(ui->xp_bar_bg,
    (sfVector2f){202.0f, 16.0f});
    ui->xp_icon = sfSprite_create();
    sfSprite_setTexture(ui->xp_icon, xp, sfTrue);
    sfSprite_setOrigin(ui->xp_icon, (sfVector2f){16, 16});
    sfSprite_setScale(ui->xp_icon, (sfVector2f){1.5, 1.5});
}
