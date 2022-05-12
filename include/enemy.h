/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy.h
*/

#pragma once

#include "my_rpg.h"

enum enemy_type {
    ARMORED_SKELETON,
    SKELETON,
    KNIGHT
};

enum enemy_state {
    E_ATTACK,
    E_DAMAGE,
    E_DEATH,
    E_IDLE,
    E_MOVEMENT
};

enum enemy_direction {
    E_DOWN,
    E_LEFT,
    E_RIGHT,
    E_UP
};

typedef struct enemy_textures {
    sfTexture *attack[4];
    sfTexture *damage[4];
    sfTexture *death[4];
    sfTexture *idle[4];
    sfTexture *movement[4];
} enemy_textures_t;

typedef struct enemy_rect {
    sfVector3f attack[4];
    sfVector3f damage[4];
    sfVector3f death[4];
    sfVector3f idle[4];
    sfVector3f movement[4];
} enemy_rect_t;

typedef struct e_stats {
    float speed;
    int health;
    int max_health;
    int attack;
    int defense;
    int level;
    int xp_reward;
} e_stats_t;

struct enemy;

typedef struct e_ui {
    sfText *level;
    sfRectangleShape *health_bar;
    sfRectangleShape *health_bar_bg;
    void (*update)(struct enemy *enemy);
    void (*draw)(struct enemy *enemy);
} e_ui_t;

typedef struct enemy {
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f velocity;
    enemy_textures_t textures;
    enemy_rect_t rect;
    e_stats_t stats;
    e_ui_t ui;
    int id;
    int type;
    char *name;
    int state;
    int direction;
    void (*update)(struct enemy *enemy);
    void (*draw)(struct enemy *enemy);
    void (*animate)(struct enemy *enemy);
    void (*move)(struct enemy *enemy);
    void (*pathfind)(struct enemy *enemy);
    void (*set_state)(struct enemy *enemy, int state);
    void (*set_direction)(struct enemy *enemy, int direction);
    void (*set_level)(struct enemy *enemy, int level);
    void (*set_health)(struct enemy *enemy, int health);
} enemy_t;

void initialize_enemies(void);
void initialize_enemy_ui(enemy_t *enemy);
void initialize_enemy_textures(enemy_t *enemy,
char **enemy_data);
enemy_t *spawn_enemy(int type, sfVector2f pos);
void kill_enemy(enemy_t *enemy);
void spawner(void);
