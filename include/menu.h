/*
** EPITECH PROJECT, 2022
** menu.h
** File description:
** menu tools
*/

#pragma once

#include "my_rpg.h"

typedef struct buttons_s {
    bool texture;
    bool colored;
    bool event;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
} buttons_t;

typedef struct menu_s {
    int state;
    int buttons_nb;
    sfRectangleShape **background;
    buttons_t *buttons;
    void (*update)(void);
    void (*draw)(void);
} menu_t;

typedef struct textures_s {
    bool texture;
} textures_t;

typedef struct colored_s {
    bool colored;
} colored_t;

typedef struct events_s {
    bool event;
} events_t;

typedef struct position_s {
    sfVector2f position;
} position_t;

typedef struct sizes_s {
    sfVector2f size;
} sizes_t;

typedef struct colour_s {
    sfColor colour;
} colour_t;

static const textures_t texture[] = {
    {true},
    {false},
    {false},
    {false},
    {false},
    {true},
    {true},
    {true},
    {true},
    {true},
    {true},
    {true},
    {true},
    {true},
    {true},
    {true},
    {true},
    {false}
};

static const colored_t colored[] = {
    {false},
    {true},
    {true},
    {true},
    {true},
    {false},
    {false},
    {false},
    {false},
    {true},
    {true},
    {true},
    {true},
    {true},
    {false},
    {true},
    {true},
    {true}
};

static const events_t event[] = {
    {false},
    {true},
    {true},
    {true},
    {true},
    {false},
    {false},
    {false},
    {false},
    {true},
    {true},
    {true},
    {true},
    {true},
    {false},
    {true},
    {true},
    {false}
};

static const position_t position[] = {
    {(sfVector2f){0.0f, 0.0f}},
    {(sfVector2f){0.0f, 0.0f}},
    {(sfVector2f){0.0f, 360.0f}},
    {(sfVector2f){640.0f, 0.0f}},
    {(sfVector2f){640.0f, 360.0f}},
    {(sfVector2f){133.3f, 100.0f}},
    {(sfVector2f){200.0f, 373.3f}},
    {(sfVector2f){700.0f, 140.0f}},
    {(sfVector2f){760.3f, 420.0f}},
    {(sfVector2f){150.0f, 520.0f}},
    {(sfVector2f){300.0f, 520.0f}},
    {(sfVector2f){450.0f, 520.0f}},
    {(sfVector2f){850.0f, 100.0f}},
    {(sfVector2f){1050.0f, 100.0f}},
    {(sfVector2f){940.0f, 120.0f}},
    {(sfVector2f){850.0f, 250.0f}},
    {(sfVector2f){1050.0f, 250.0f}},
    {(sfVector2f){920.0f, 265.0f}}
};

static const sizes_t size[] = {
    {(sfVector2f){1280.0f, 720.0f}},
    {(sfVector2f){640.0f, 360.0f}},
    {(sfVector2f){640.0f, 360.0f}},
    {(sfVector2f){640.0f, 360.0f}},
    {(sfVector2f){640.0f, 360.0f}},
    {(sfVector2f){400.0f, 200.0f}},
    {(sfVector2f){266.6f, 100.0f}},
    {(sfVector2f){100.0f, 100.0f}},
    {(sfVector2f){450.0f, 200.0f}},
    {(sfVector2f){80.0f, 80.0f}},
    {(sfVector2f){80.0f, 80.0f}},
    {(sfVector2f){80.0f, 80.0f}},
    {(sfVector2f){60.0f, 60.0f}},
    {(sfVector2f){60.0f, 60.0f}},
    {(sfVector2f){80.0f, 30.0f}},
    {(sfVector2f){60.0f, 60.0f}},
    {(sfVector2f){60.0f, 60.0f}},
    {(sfVector2f){120.0f, 30.0f}}
};

static const colour_t color[] = {
    {(sfColor){0, 0, 255, 100}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 255, 100}},
    {(sfColor){0, 0, 255, 100}},
    {(sfColor){0, 0, 255, 100}},
    {(sfColor){0, 0, 255, 100}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}},
    {(sfColor){0, 0, 0, 255}}
};

// SETUP

void initialize_menu(void);
buttons_t *initialize_buttons(int buttons_nb);

// EVENT

void menu_update(void);
void menu_event(void);
void reduce_sound(sfRectangleShape *rect);
void increase_sound(sfRectangleShape *rect);
void increase_fps(sfRectangleShape *rect);
void reduce_fps(sfRectangleShape *rect);
void start_game(void);
