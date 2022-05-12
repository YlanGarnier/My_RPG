/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player.c
*/

#include "game.h"
#include "player.h"

static void update(void)
{
    player_t *player = &game()->player;
    player_ui_t *ui = &player->ui;
    camera_t *camera = &player->camera;
    inventory_t *inventory = &player->inventory;
    stats_menu_t *menu = &player->stats_menu;

    player->velocity = (sfVector2f){0.0f, 0.0f};
    player->position = sfSprite_getPosition(player->sprite);
    player->handle_event();
    if (game()->state == 2)
        return;
    player->move();
    player->position = sfSprite_getPosition(player->sprite);
    ui->update();
    animate_sword();
    camera->update();
    inventory->update();
    menu->update();
    sfRectangleShape_setPosition(player->attack_box,
    (sfVector2f){player->position.x, player->position.y + 5});
}

static void draw(void)
{
    sfRenderWindow *window = game()->window.sf_window;
    player_t *player = &game()->player;
    player_ui_t *ui = &player->ui;
    map_t *map = &game()->map;
    camera_t *camera = &player->camera;

    if (game()->player.attacking)
        sfRenderWindow_drawSprite(window, game()->player.sword_sprite, NULL);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    display_tiles(map->layers_nb[ALL] - 1, map);
    camera->draw_effects();
    ui->draw();
    player->inventory.draw();
    player->stats_menu.draw();
}

void initialize_player(void)
{
    game()->player.update = update;
    game()->player.draw = draw;
    game()->player.attacking = 0;
    game()->player.animation_clock = sfClock_create();
    game()->player.attack_clock = sfClock_create();
    game()->player.direction = UP;
    game()->player.state = IDLE;
    game()->player.sprite = sfSprite_create();
    game()->player.sword_sprite = sfSprite_create();
    initialize_stats();
    initialize_camera();
    initialize_animation();
    initialize_event();
    initialize_movement();
    initialize_textures();
    initialize_ui();
    initialize_inventory();
    initialize_attack();
    initialize_hitbox();
    add_item(SPEED_POTION);
    add_item(SPEED_POTION);
    add_item(SPEED_POTION);
    add_item(SPEED_POTION);
}
