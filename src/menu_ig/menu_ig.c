/*
** EPITECH PROJECT, 2022
** menu_in_game
** File description:
** menu_in_game
*/

#include "game.h"

void menu_ig_event(sfEvent event);

static void update_buttons_pos(window_t *window, sfRectangleShape *bg,
button_t *button, sfVector2f player_pos)
{
    sfRectangleShape_setPosition(bg, (sfVector2f)
    {player_pos.x - window->width / 2, player_pos.y - window->height / 2});
    for (int i = 0; i < 2; ++i)
        sfRectangleShape_setPosition(button[i].shape, (sfVector2f)
        {player_pos.x - button[i].size.x / 2, player_pos.y - window->height / 2
        + button[i].pos.y});
    for (int i = 2; i < 5; ++i) {
        sfRectangleShape_setPosition(button[i].shape, (sfVector2f)
        {player_pos.x - window->width / 2 + button[i].pos.x, player_pos.y -
        window->height / 2 + button[i].pos.y});
    }
}

static void destroy(void)
{
    menu_ig_t *menu_ig = &game()->menu_ig;

    for (int i = 0; i < 5; ++i)
        sfRectangleShape_destroy(menu_ig->button[i].shape);
    free(menu_ig->button);
    sfTexture_destroy(menu_ig->bg_texture);
}

static void update(void)
{
    window_t *window = &game()->window;
    menu_ig_t *menu_ig = &game()->menu_ig;
    sfVector2f player_pos = game()->player.position;

    update_buttons_pos(window, menu_ig->bg, menu_ig->button, player_pos);
    sfRenderWindow_drawRectangleShape(window->sf_window,
    menu_ig->bg, NULL);
    for (int i = 0; i < 5; ++i) {
        sfRenderWindow_drawRectangleShape(window->sf_window,
        menu_ig->button[i].shape, NULL);
    }
}

static button_t *set_button(sfTexture *menu_texture, sfTexture *leave_texture,
sfTexture *save_texture)
{
    window_t *window = &game()->window;
    button_t *button = malloc(sizeof(buttons_t) * 5);
    sfVector2f buttons_size = {500, 100};
    for (int i = 0, y = 100, x = window->width / 2 -
        buttons_size.x / 2; i < 2; ++i, y += buttons_size.y * 2) {
        button[i].shape = sfRectangleShape_create();
        button[i].pos = (sfVector2f) {x, y};
        button[i].size = buttons_size;
        sfRectangleShape_setSize(button[i].shape, buttons_size);
    }
    sfRectangleShape_setTexture(button[0].shape, menu_texture, sfFalse);
    sfRectangleShape_setTexture(button[1].shape, leave_texture, sfFalse);
    for (int i = 2, y = 500, x = 390; i < 5; ++i, x += 200) {
        button[i].shape = sfRectangleShape_create();
        button[i].pos = (sfVector2f) {x, y};
        button[i].size = (sfVector2f) {100, 100};
        sfRectangleShape_setSize(button[i].shape, (sfVector2f) {100, 100});
        sfRectangleShape_setTexture(button[i].shape, save_texture, sfFalse);
    }
    return button;
}

menu_ig_t init_menu_ig(void)
{
    menu_ig_t menu_ig;
    window_t *window = &game()->window;

    menu_ig.bg = sfRectangleShape_create();
    sfRectangleShape_setSize(menu_ig.bg, (sfVector2f) {window->width,
    window->height});
    sfRectangleShape_setFillColor(menu_ig.bg, (sfColor) {100, 0, 0, 100});
    menu_ig.menu_texture = sfTexture_createFromFile(
    "assets/menu/button_menu.png", NULL);
    menu_ig.leave_texture = sfTexture_createFromFile(
    "assets/menu/button_leave.png", NULL);
    menu_ig.save_texture = sfTexture_createFromFile(
    "assets/menu/save.png", NULL);
    menu_ig.button = set_button(menu_ig.menu_texture, menu_ig.leave_texture,
    menu_ig.save_texture);
    menu_ig.update = update;
    menu_ig.destroy = destroy;
    menu_ig.event = menu_ig_event;
    return menu_ig;
}
