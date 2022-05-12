/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** game.h
*/

#pragma once

#include "my_rpg.h"

typedef struct window {
    int width;
    int height;
    unsigned int fps;
    sfEvent event;
    sfRenderWindow *sf_window;
    void (*clear)(void);
    void (*update)(void);
    void (*destroy)(void);
    sfBool (*opened) (void);
} window_t;

// WINDOW
window_t create_window(char const *name, int width, int height);

// EVENT
void check_close(sfEvent event);
