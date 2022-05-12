/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** player.h
*/

#pragma once

#include "my_rpg.h"
#include "item.h"

#define POS map[0][tile.y][tile.x]
#define UPPER map[0][tile.y - 1][tile.x]
#define UNDER map[0][tile.y + 1][tile.x]
#define ON_LEFT map[0][tile.y][tile.x - 1]
#define ON_RIGHT map[0][tile.y][tile.x + 1]

enum player_state {
    IDLE,
    WALK,
    SPRINT,
    DEAD
};

enum player_direction {
    DOWN,
    LEFT,
    RIGHT,
    UP
};

typedef struct animation_sprite {
    sfTexture *moove_top[8];
    sfTexture *moove_bot[8];
    sfTexture *moove_left[8];
    sfTexture *moove_right[8];
    sfTexture *attack_sword[22];
} animation_sprite_t;

typedef struct camera {
    sfView *view;
    sfSprite *lantern;
    void (*update)(void);
    void (*draw_effects)(void);
} camera_t;

typedef struct slot {
    int x, y;
    int empty;
    item_t *item;
    sfSprite *item_sprite;
    sfRectangleShape *ui;
    void (*update)(struct slot *);
    void (*draw)(struct slot *);
} slot_t;

typedef struct inventory {
    sfSprite *sprite;
    int open;
    int slot_count;
    int empty_slot;
    slot_t slots[5][7];
    void (*update)(void);
    void (*draw)(void);
} inventory_t;

typedef struct stats_button {
    sfSprite *sprite;
    sfSprite *button;
    sfSprite *pressed;
    int *stat;
} stats_button_t;

typedef struct stats_menu {
    sfSprite *background;
    sfText *title;
    sfText *stats_point;
    sfText *health;
    sfText *speed;
    sfText *attack;
    sfText *defense;
    stats_button_t health_button;
    stats_button_t speed_button;
    stats_button_t attack_button;
    stats_button_t defense_button;
    int open;
    void (*update)(void);
    void (*draw)(void);
} stats_menu_t;

typedef struct stats {
    int level;
    int xp;
    int max_xp;
    int stats_point;
    int health;
    int max_health;
    int speed;
    int attack;
    int defense;
} stats_t;

typedef struct player_ui {
    sfRectangleShape *health_bar, *health_bar_bg;
    sfSprite *health_icon;
    sfRectangleShape *xp_bar, *xp_bar_bg;
    sfSprite *xp_icon;
    void (*update)(void);
    void (*draw)(void);
} player_ui_t;

typedef struct player {
    int state, attacking, direction;
    sfRectangleShape *attack_box;
    sfVector2f velocity, position;
    sfSprite *sprite, *sword_sprite;
    sfClock *animation_clock, *attack_clock;
    animation_sprite_t sprites;
    camera_t camera;
    inventory_t inventory;
    stats_menu_t stats_menu;
    stats_t stats;
    player_ui_t ui;
    void (*update)(void);
    void (*draw)(void);
    void (*animate)(void);
    void (*move)(void);
    void (*handle_event)(void);
    void (*attack)(void);
    void (*set_health)(int health);
    void (*set_point)(int point);
    void (*set_xp)(int xp);
} player_t;

// SETUP

void initialize_player(void);
void initialize_animation(void);
void initialize_event(void);
void initialize_movement(void);
void initialize_camera(void);
void initialize_textures(void);
void initialize_inventory(void);
void initialize_attack(void);
void initialize_hitbox(void);
void initialize_health_bar(void);
void initialize_xp_bar(void);
void initialize_stats(void);
void initialize_stats_button(void);
void initialize_ui(void);
sfTexture *choose_texture(int i);

// INVENTORY

void initialize_slot(int x, int y);
slot_t *find_empty_slot(void);
void add_item(int id);
void remove_item(slot_t *slot);
void use_item(slot_t *slot, item_t *item);

// HEALTH

void update_health_position(void);

// XP

void update_xp_position(void);

// ANIMATION

void animate_player(void);
void animate_sword(void);

// MOVEMENT

void move_player(void);
void update_position(void);
bool check_vertical(int direction, int mode, int col);
bool check_horizontal(int direction, int mode, int col);
bool player_upper_col(void);
bool player_under_col(void);
bool player_right_col(void);
bool player_left_col(void);

// EVENT

void check_chests(void);
void check_dungeon(void);
int check_pnj(void);

// STATS

void upgrade_stats(stats_button_t *button, sfText *text, char *string);
