/*
** EPITECH PROJECT, 2022
** map
** File description:
** all map functions
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "game.h"
#include "my_rpg.h"
#include "map.h"
#include "my.h"

int display_ray_tiles(tiles_t tiles)
{
    window_t window = game()->window;
    sfVector2f pos;
    sfVector2f dir;
    float distance;

    pos = sfRectangleShape_getPosition(tiles.shape);
    dir.x = pos.x - game()->player.position.x;
    dir.y = pos.y - game()->player.position.y;
    distance = sqrt(dir.x * dir.x + dir.y * dir.y);
    if (tiles.id != -1 && fabsf(distance) < 780.0f)
        sfRenderWindow_drawRectangleShape(window.sf_window, tiles.shape, NULL);
return 0;
}

void display_tiles(int layer, map_t *map)
{
    for (int y = 0; y < map->info_size[0]; ++y)
        for (int x = 0; x < map->info_size[1]; ++x)
            display_ray_tiles(map->layers[layer].tiles[y][x]);
}

void destroy_tiles(int layer, map_t *map)
{
    for (int y = 0; y < map->info_size[0]; ++y) {
        free(map->layers[layer].tiles[y]);
        for (int x = 0; x < map->info_size[1]; ++x)
            sfRectangleShape_destroy(map->layers[layer].tiles[y][x].shape);
        free(map->layers[layer].tiles[y]);
    }
    free(map->layers[layer].tiles);
}

sfIntRect get_tile_rect(int id, int x_max)
{
    sfIntRect rect = { 0, 0, 16, 16 };

    if (id == -1)
        id = 11;
    for (int count = 0; count < id; ++count) {
        if (rect.left + 16 >= x_max - 16) {
            rect.left = 0;
            rect.top += 16;
        } else
            rect.left += 16;
    }
    return rect;
}

void set_layer_tiles(map_t *map, layers_t *layer)
{
    sfVector2f tile_size = {20 * ZOOM, 20 * ZOOM};
    sfVector2f pos = { 0, 0 };
    sfIntRect rec;
    int height = map->info_size[0];
    int width = map->info_size[1];

    layer->tiles = malloc(sizeof(tiles_t*) * height);
    for (int y = 0; y < height; ++y, pos.y += tile_size.y) {
        layer->tiles[y] = malloc(sizeof(tiles_t) * width);
        pos.x = 0;
        for (int x = 0; x < width; ++x, pos.x += tile_size.x) {
            rec = get_tile_rect(layer->info[y][x], map->texture_size.x);
            layer->tiles[y][x].id = layer->info[y][x];
            layer->tiles[y][x].shape = sfRectangleShape_create();
            sfRectangleShape_setTexture(layer->tiles[y][x].shape,
                                        map->texture, sfFalse);
            sfRectangleShape_setSize(layer->tiles[y][x].shape, tile_size);
            sfRectangleShape_setTextureRect(layer->tiles[y][x].shape, rec);
            sfRectangleShape_setPosition(layer->tiles[y][x].shape, pos);
        }
    }
}
