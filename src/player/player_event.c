/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_event.c
*/

#include "game.h"
#include "chatbox.h"
#include "player.h"
#include "map.h"

static void check_keys(sfEvent event)
{
    window_t *window = &game()->window;
    player_t *player = &game()->player;
    chatbox_t *chatbox = &game()->chatbox;

    if (game()->state == 2 && event.key.code == sfKeyEscape) {
        game()->state = 1;
        return;
    }
    chatbox->event(window, chatbox, &game()->state);
    if (event.key.code == sfKeyI) {
        if (player->stats_menu.open) return;
        player->inventory.open = player->inventory.open == 0 ? 1 : 0;
    }
    if (event.key.code == sfKeyP) {
        if (player->inventory.open) return;
        player->stats_menu.open = player->stats_menu.open == 0 ? 1 : 0;
    }
    if (event.key.code == sfKeyE)
        check_chests();
}

static void check_event(sfEvent event)
{
    chatbox_t *chatbox = &game()->chatbox;
    stats_menu_t *menu = &game()->player.stats_menu;
    menu_ig_t *menu_ig = &game()->menu_ig;

    check_close(event);
    if (event.type == sfEvtKeyReleased)
        check_keys(event);
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.mouseButton.button == sfMouseLeft) {
            upgrade_stats(&menu->health_button, menu->health, "Health -> ");
            upgrade_stats(&menu->attack_button, menu->attack, "Attack -> ");
            upgrade_stats(&menu->defense_button, menu->defense, "Defense -> ");
            upgrade_stats(&menu->speed_button, menu->speed, "Speed -> ");
        }
        menu_ig->event(event);
    }
}

static void check_movement(void)
{
    player_t *player = &game()->player;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        if (player_upper_col())
            player->velocity.y -= (player->stats.speed * ZOOM) * 10 *
            game()->delta_time;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        if (player_under_col())
            player->velocity.y += (player->stats.speed * ZOOM) * 10 *
            game()->delta_time;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        if (player_right_col())
            player->velocity.x += (player->stats.speed * ZOOM) * 10 *
            game()->delta_time;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        if (player_left_col())
            player->velocity.x -= (player->stats.speed * ZOOM) * 10 *
            game()->delta_time;
}

static void handle_event(void)
{
    window_t *window = &game()->window;
    player_t *player = &game()->player;

    check_movement();
    check_dungeon();
    if (sfKeyboard_isKeyPressed(sfKeySpace) && !player->attacking) {
        player->attack();
        sfSound_play(game()->sounds[3].sound);
    }
    while (sfRenderWindow_pollEvent(window->sf_window, &window->event))
        check_event(window->event);
}

void initialize_event(void)
{
    game()->player.handle_event = handle_event;
}
