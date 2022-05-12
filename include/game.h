/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** game.h
*/

#pragma once

#include "my_rpg.h"
#include "menu_ig.h"
#include "map.h"
#include "window.h"
#include "player.h"
#include "menu.h"
#include "chatbox.h"
#include "enemy.h"
#include "entities.h"
#include "sound.h"

enum game_state {
    MENU,
    GAME,
    MENU_IG
};

typedef struct game {
    int state;
    window_t window;
    menu_ig_t menu_ig;
    map_t map;
    player_t player;
    chatbox_t chatbox;
    menu_t *menu;
    sfClock *clock;
    sfVector2f velocity;
    item_t *items;
    enemy_t *enemies;
    sound_t *sounds;
    entities_t entities;
    float delta_time;
    void (*update)(void);
    void (*menu_update)(void);
    void (*destroy)(void);
} game_t;

typedef struct scene_s {
    int state;
    void (*ptr)(void);
} scene_t;

// GAME
game_t *game(void);
game_t *initialize_game(void);
