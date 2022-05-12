/*
** EPITECH PROJECT, 2022
** map
** File description:
** all map functions
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_rpg.h"
#include "map.h"
#include "my.h"

static void initialize_world(char **infos, map_t *map)
{
    char **line;

    map->layers_nb = malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++)
        map->layers_nb[i] = 0;
    for (int i = 0; infos[i] != NULL; i++) {
        line = my_str_to_word_array(infos[i], '=');
        map->layers_nb[ALL] += 1;
        if (my_strcmp(line[0], "background") == 0)
            map->layers_nb[BACKGROUND] += 1;
        if (my_strcmp(line[0], "room") == 0)
            map->layers_nb[ROOMS] += 1;
        if (my_strcmp(line[0], "dungeon") == 0)
            map->layers_nb[DUNGEON] += 1;
    }
    map->layers = malloc(sizeof(layers_t) * map->layers_nb[ALL]);
}

static int **read_csv(map_t *map, layers_t *layer)
{
    char *content = my_readfile(layer->path);
    char **txt_csv = my_str_to_word_array(content, '\n');
    char **line;
    int **int_csv;

    map->info_size = malloc(sizeof(int) * 2);
    map->info_size[0] = my_arraylen(txt_csv);
    int_csv = malloc(sizeof(int*) * map->info_size[0]);
    for (int y = 0; y < map->info_size[0]; ++y) {
        line = my_str_to_word_array(txt_csv[y], ',');
        if (y == 0)
            map->info_size[1] = my_arraylen(line);
        int_csv[y] = malloc(sizeof(int) * map->info_size[1]);
        for (int x = 0; x < map->info_size[1]; ++x)
            int_csv[y][x] = my_getnbr(line[x]);
        my_free_array(line);
    }
    free(content);
    my_free_array(txt_csv);
    return int_csv;
}

static void set_collision(char *str, layers_t *layers)
{
    if (my_strcmp(str, "collisions") == 0)
        layers->col = COL;
    if (my_strcmp(str, "background") == 0)
        layers->col = NOTHING;
    if (my_strcmp(str, "chest") == 0)
        layers->col = CHESTS;
    if (my_strcmp(str, "goldenchest") == 0)
        layers->col = GOLDENCHESTS;
    if (my_strcmp(str, "dungeon") == 0)
        layers->col = DUNGEONS;
    if (my_strcmp(str, "pnj") == 0)
        layers->col = PNJS;
}

static void set_info_layer(map_t *map, layers_t *layer)
{
    layer->info = read_csv(map, layer);
    get_collisions(map, layer);
}

void set_map_infos(map_t *map)
{
    char *buffer = my_readfile("config/map.config");
    char **infos = my_str_to_word_array(buffer, '\n');
    char **line;

    initialize_world(infos, map);
    for (int i = 0; infos[i] != NULL; ++i) {
        line = my_str_to_word_array(infos[i], '=');
        map->layers[i].zone = line[0];
        map->layers[i].path = line[2];
        set_collision(line[1], &map->layers[i]);
        set_info_layer(map, &map->layers[i]);
        my_free_array(line);
    }
    my_free_array(infos);
    free(buffer);
}
