/*
** EPITECH PROJECT, 2022
** menu_background.c
** File description:
** background
*/

#include "game.h"

void button_update(int state, int i);
void check_event(int state, int i);
bool check_click(int state);
bool check_idle(sfRectangleShape *rect);

void menu_update(void)
{
    buttons_t *buttons = game()->menu->buttons;
    static int state = 0;

    for (int i = 0; i < game()->menu->buttons_nb; i++) {
        if (buttons[i].event && buttons[i].colored) {
            state = check_idle(game()->menu->background[i]);
            button_update(state, i);
            state = check_click(state);
            check_event(state, i);
            state = 0;
        }
    }
}

static sfRectangleShape *set_rect(sfTexture *text, buttons_t button)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, button.size);
    sfRectangleShape_setPosition(rect, button.pos);
    if (button.texture)
        sfRectangleShape_setTexture(rect, text, sfFalse);
    if (button.colored)
        sfRectangleShape_setFillColor(rect, button.color);
    return rect;
}

static sfRectangleShape **create_buttons(sfTexture **text, int buttons_nb)
{
    sfRectangleShape **rect = malloc(sizeof(sfRectangleShape*) * buttons_nb);
    buttons_t *buttons = game()->menu->buttons;

    for (int i = 0; i < game()->menu->buttons_nb; i++)
        rect[i] = set_rect(text[i], buttons[i]);
    sfRectangleShape_setTextureRect(rect[14], (sfIntRect){0, 130, 234, 130});
    return rect;
}

static sfTexture **background_textures(int buttons_nb)
{
    sfTexture **text = malloc(sizeof(sfTexture*) * buttons_nb);
    text[0] = sfTexture_createFromFile("assets/menu/background.png", NULL);
    text[5] = sfTexture_createFromFile("assets/menu/start.png", NULL);
    text[6] = sfTexture_createFromFile("assets/menu/load.png", NULL);
    text[7] = sfTexture_createFromFile("assets/menu/parameters.png", NULL);
    text[8] = sfTexture_createFromFile("assets/menu/leave.png", NULL);
    text[9] = sfTexture_createFromFile("assets/menu/save.png", NULL);
    text[10] = sfTexture_createFromFile("assets/menu/save.png", NULL);
    text[11] = sfTexture_createFromFile("assets/menu/save.png", NULL);
    text[12] = sfTexture_createFromFile("assets/menu/left_arrow.png", NULL);
    text[13] = sfTexture_createFromFile("assets/menu/right_arrow.png", NULL);
    text[14] = sfTexture_createFromFile("assets/menu/fps.png", NULL);
    text[15] = sfTexture_createFromFile("assets/menu/left_arrow.png", NULL);
    text[16] = sfTexture_createFromFile("assets/menu/right_arrow.png", NULL);
    return text;
}

sfRectangleShape **initialize_background(void)
{
    menu_t *menu = game()->menu;
    menu->buttons_nb = 18;
    menu->buttons = initialize_buttons(menu->buttons_nb);
    sfTexture **text = background_textures(menu->buttons_nb);
    sfRectangleShape **rect = create_buttons(text, menu->buttons_nb);
    return rect;
}
