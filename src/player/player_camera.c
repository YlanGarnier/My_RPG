/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_animation.c
*/

#include "game.h"
#include "player.h"

static void draw_effects(void)
{
    sfRenderWindow *window = game()->window.sf_window;
    camera_t *camera = &game()->player.camera;

    sfRenderWindow_drawSprite(window, camera->lantern, NULL);
}

static void update(void)
{
    player_t *player = &game()->player;
    camera_t *camera = &game()->player.camera;

    sfView_setCenter(player->camera.view, player->position);
    sfSprite_setPosition(camera->lantern, player->position);
    sfRenderWindow_setView(game()->window.sf_window, player->camera.view);
}

static void initialize_effects(void)
{
    camera_t *camera = &game()->player.camera;
    sfVector2f origin = {game()->window.width / 2, game()->window.height / 2};
    sfTexture* lantern = sfTexture_createFromFile("assets/player/lantern.png",
    NULL);

    camera->lantern = sfSprite_create();
    sfSprite_setTexture(camera->lantern, lantern, sfTrue);
    sfSprite_setOrigin(camera->lantern, origin);
}

void initialize_camera(void)
{
    camera_t *camera = &game()->player.camera;
    sfVector2f cam_size = {game()->window.width, game()->window.height};

    camera->update = update;
    camera->draw_effects = draw_effects;
    camera->view = sfView_create();
    sfView_setSize(camera->view, cam_size);
    initialize_effects();
}
