/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_stats_button.c
*/

#include "game.h"
#include "player.h"

static void initialize_button(stats_button_t *button, int *stat)
{
    sfTexture *t = sfTexture_createFromFile("assets/menu/button.png", NULL);
    sfTexture *t_p = sfTexture_createFromFile("assets/menu/button_press.png",
    NULL);
    sfVector2f origin = {128.0, 128.0};
    sfVector2f scale = {0.10, 0.10};
    sfColor color = {217, 185, 126, 255};

    button->button = sfSprite_create();
    sfSprite_setTexture(button->button, t, sfTrue);
    sfSprite_setOrigin(button->button, origin);
    sfSprite_setScale(button->button, scale);
    sfSprite_setColor(button->button, color);
    button->pressed = sfSprite_create();
    sfSprite_setTexture(button->pressed, t_p, sfTrue);
    sfSprite_setOrigin(button->pressed, origin);
    sfSprite_setScale(button->pressed, scale);
    sfSprite_setColor(button->pressed, color);
    button->sprite = button->button;
    button->stat = stat;
}

void upgrade_stats(stats_button_t *button, sfText *text, char *string)
{
    player_t *player = &game()->player;
    sfRenderWindow *window = game()->window.sf_window;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game()->window.sf_window,
    mouse_pos, game()->player.camera.view);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);

    if (player->stats.stats_point < 1)
        return;
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        *(button->stat) += 2;
        if (my_strcmp(string, "Health -> ") == 0)
            game()->player.set_health(*(button->stat));
        player->set_point(player->stats.stats_point - 1);
        sfText_setString(text, cat_text(string, my_itoa(*(button->stat))));
    }
}

void initialize_stats_button(void)
{
    player_t *player = &game()->player;
    stats_menu_t *menu = &player->stats_menu;

    initialize_button(&menu->health_button, &player->stats.max_health);
    initialize_button(&menu->attack_button, &player->stats.attack);
    initialize_button(&menu->defense_button, &player->stats.defense);
    initialize_button(&menu->speed_button, &player->stats.speed);
}
