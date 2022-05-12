/*
** EPITECH PROJECT, 2022
** map tools
** File description:
** all map tools
*/

#include "my_rpg.h"
#include "map.h"
#include "window.h"
#include "game.h"

void display_map(void)
{
    map_t *map = &game()->map;

    for (int layer = 0; layer < map->layers_nb[ALL]; ++layer)
        display_tiles(layer, map);
}

void destroy(map_t *map)
{
    for (int layer = 0; layer < map->layers_nb[ALL]; ++layer)
        destroy_tiles(layer, map);
}

void create(map_t *map)
{
    set_map_infos(map);
    for (int i = 0; i < map->layers_nb[ALL]; ++i)
        set_layer_tiles(map, &map->layers[i]);
}
