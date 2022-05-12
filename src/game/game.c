/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** game().c
*/

#include "game.h"
#include "save.h"
#include "enemy.h"

static void destroy(void)
{
    menu_ig_t *menu_ig = &game()->menu_ig;
    chatbox_t *chatbox = &game()->chatbox;

    chatbox->destroy(chatbox);
    return;
}

static void update(void)
{
    player_t *player = &game()->player;
    window_t *window = &game()->window;
    menu_ig_t *menu_ig = &game()->menu_ig;
    entities_t *entities = &game()->entities;
    map_t *map = &game()->map;
    chatbox_t *chatbox = &game()->chatbox;

    window->clear();
    if (chatbox->chat_index <= 0) {
        game()->delta_time = get_delta_time();
        entities->update();
    }
    player->update();
    map->display();
    entities->draw();
    player->draw();
    chatbox->update(chatbox, window, player);
    if (game()->state == 2)
        menu_ig->update();
    window->update();
}

game_t *initialize_game(void)
{
    game()->update = update;
    game()->destroy = destroy;
    game()->window = create_window("My_RPG", 1280, 720);
    game()->clock = sfClock_create();
    game()->map = init_map();
    game()->map.create(&game()->map);
    initialize_items();
    initialize_enemies();
    initialize_entities();
    initialize_player();
    initialize_sounds();
    initialize_menu();
    game()->chatbox = init_chatbox(&game()->window, &game()->player);
    game()->menu_ig = init_menu_ig();
    spawner();
    return game();
}
