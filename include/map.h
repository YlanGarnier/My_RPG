/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** map.h
*/

#pragma once

#include "my_rpg.h"

static const int NO_COL = 1;
static const int COLLI = -1;
static const int CHEST = -2;
static const int GOLDEN = -3;
static const int DUNG = -4;
static const int PNJ = -5;
static const int TILE_LEFT = -1;
static const int TILE_RIGHT = 1;
static const int TILE_UP = -1;
static const int TILE_DOWN = 1;

typedef enum which_layer {
    ALL,
    BACKGROUND,
    ROOMS,
    DUNGEON
} which_layer_e;

typedef enum which_col {
    NOTHING,
    COL,
    CHESTS,
    GOLDENCHESTS,
    DUNGEONS,
    PNJS
} which_col_e;

typedef struct tiles_s {
    int id;
    sfRectangleShape *shape;
} tiles_t;

typedef struct layers_s {
    int col;
    char *zone;
    char *path;
    int **info;
    tiles_t **tiles;
} layers_t;

typedef struct map_s {
    int *info_size;
    int *layers_nb;
    int **back_col;
    int **room_col;
    int **dung_col;
    sfTexture *texture;
    sfVector2u texture_size;
    layers_t *layers;
    void (*display)(void);
    void (*destroy)(struct map_s *map);
    void (*create)(struct map_s *map);
} map_t;

// SET TILES

void display_tiles(int layer, map_t *map);
void destroy_tiles(int layer, map_t *map);
sfIntRect get_tile_rect(int id, int x_max);
void set_layer_tiles(map_t *map, layers_t *layer);
void set_map_infos(map_t *map);
map_t init_map(void);

// SET COLLISIONS

void get_collisions(map_t *map, layers_t *layer);
