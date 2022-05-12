/*
** EPITECH PROJECT, 2022
** menu_ig
** File description:
** menu_ig
*/

#pragma once

#include "my_rpg.h"

typedef struct button_s {
    sfRectangleShape *shape;
    sfVector2f pos;
    sfVector2f size;
} button_t;

typedef struct menu_ig_s {
    button_t *button;
    sfRectangleShape *bg;
    sfTexture *bg_texture;
    sfTexture *menu_texture;
    sfTexture *leave_texture;
    sfTexture *save_texture;
    void (*update)(void);
    void (*destroy)(void);
    void (*event)(sfEvent event);
} menu_ig_t;

menu_ig_t init_menu_ig(void);
