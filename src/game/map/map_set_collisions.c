/*
** EPITECH PROJECT, 2022
** map_set_collisions.c
** File description:
** set collisions
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_rpg.h"
#include "map.h"
#include "my.h"

static void put_appropriate_collision(layers_t *layer, int *tile)
{
    if (layer->col == NOTHING)
        tile[0] = NO_COL;
    if (layer->col == COL)
        tile[0] = COLLI;
    if (layer->col == CHESTS)
        tile[0] = CHEST;
    if (layer->col == GOLDENCHESTS)
        tile[0] = GOLDEN;
    if (layer->col == DUNGEONS)
        tile[0] = DUNG;
    if (layer->col == PNJS)
        tile[0] = PNJ;
}

static void check_level(map_t *map, layers_t *layer, int y, int i)
{
    if (my_strcmp(layer->zone, "background") == 0)
        put_appropriate_collision(layer, &map->back_col[y][i]);
    if (my_strcmp(layer->zone, "room") == 0)
        put_appropriate_collision(layer, &map->room_col[y][i]);
    if (my_strcmp(layer->zone, "dungeon") == 0)
        put_appropriate_collision(layer, &map->dung_col[y][i]);
}

static void initiate_colmap(map_t *map)
{
    map->back_col = malloc(sizeof(int *) * map->info_size[0]);
    map->room_col = malloc(sizeof(int *) * map->info_size[0]);
    map->dung_col = malloc(sizeof(int *) * map->info_size[0]);
    for (int y = 0; y < map->info_size[0]; y++) {
        map->back_col[y] = malloc(sizeof(int) * map->info_size[1]);
        map->room_col[y] = malloc(sizeof(int) * map->info_size[1]);
        map->dung_col[y] = malloc(sizeof(int) * map->info_size[1]);
        for (int i = 0; i < map->info_size[1]; i++) {
            map->back_col[y][i] = 1;
            map->room_col[y][i] = 1;
            map->dung_col[y][i] = 1;
        }
    }
}

static void tile_not_empty(map_t *map, layers_t *layer, int y, int i)
{

    if (layer->info[y][i] != -1)
        check_level(map, layer, y, i);
}

void get_collisions(map_t *map, layers_t *layer)
{
    static int pass = 0;
    if (pass == 0)
        initiate_colmap(map);
    pass = 1;
    for (int y = 0; y != map->info_size[0]; y++)
        for (int i = 0; i != map->info_size[1]; i++)
            tile_not_empty(map, layer, y, i);
}
