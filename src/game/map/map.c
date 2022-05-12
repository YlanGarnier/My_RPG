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

void display_map(void);
void destroy(map_t *map);
void create(map_t *map);

map_t init_map(void)
{
    map_t map;

    map.texture = sfTexture_createFromFile("assets/textures.png", NULL);
    map.texture_size = sfTexture_getSize(map.texture);
    map.create = create;
    map.destroy = destroy;
    map.display = display_map;
    return map;
}
