/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_stats_manager.c
*/

#include "game.h"
#include "player.h"

static void update_button_position(void)
{
    player_t *player = &game()->player;
    stats_menu_t *menu = &player->stats_menu;
    sfVector2f pos = {player->position.x + 300, player->position.y};

    pos.x -= 35;
    pos.y -= 40;
    sfSprite_setPosition(menu->health_button.sprite, pos);
    pos.y += 40;
    sfSprite_setPosition(menu->attack_button.sprite, pos);
    pos.y += 40;
    sfSprite_setPosition(menu->defense_button.sprite, pos);
    pos.y += 40;
    sfSprite_setPosition(menu->speed_button.sprite, pos);
}

static void update_button(stats_button_t *button)
{
    sfRenderWindow *window = game()->window.sf_window;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game()->window.sf_window,
    mouse_pos, game()->player.camera.view);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);

    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        sfSprite_setColor(button->sprite, (sfColor){166, 140, 93, 255});
        button->sprite = button->button;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            button->sprite = button->pressed;
    } else {
        sfSprite_setColor(button->sprite, (sfColor){217, 185, 126, 255});
        button->sprite = button->button;
    }
}

void set_point(int point)
{
    player_t *player = &game()->player;
    stats_menu_t *menu = &game()->player.stats_menu;

    player->stats.stats_point = point;
    sfText_setString(menu->stats_point, cat_text("Point : ",
    my_itoa(player->stats.stats_point)));
}

void update(void)
{
    player_t *player = &game()->player;
    stats_menu_t *menu = &player->stats_menu;
    sfVector2f pos = {player->position.x + 300, player->position.y};
    sfSprite_setPosition(menu->background, pos);
    pos.x -= 180;
    pos.y -= 125;
    sfText_setPosition(menu->title, pos);
    pos.y += 40;
    sfText_setPosition(menu->stats_point, pos);
    pos.y += 40;
    sfText_setPosition(menu->health, pos);
    pos.y += 40;
    sfText_setPosition(menu->attack, pos);
    pos.y += 40;
    sfText_setPosition(menu->defense, pos);
    pos.y += 40;
    sfText_setPosition(menu->speed, pos);
    update_button_position();
    update_button(&menu->health_button);
    update_button(&menu->attack_button);
    update_button(&menu->defense_button);
    update_button(&menu->speed_button);
}

void draw(void)
{
    sfRenderWindow *window = game()->window.sf_window;
    stats_menu_t *menu = &game()->player.stats_menu;

    if (!menu->open)
        return;
    sfRenderWindow_drawSprite(window, menu->background, NULL);
    sfRenderWindow_drawText(window, menu->title, NULL);
    sfRenderWindow_drawText(window, menu->stats_point, NULL);
    sfRenderWindow_drawText(window, menu->health, NULL);
    sfRenderWindow_drawText(window, menu->attack, NULL);
    sfRenderWindow_drawText(window, menu->defense, NULL);
    sfRenderWindow_drawText(window, menu->speed, NULL);
    sfRenderWindow_drawSprite(window, menu->health_button.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->attack_button.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->defense_button.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->speed_button.sprite, NULL);
}
