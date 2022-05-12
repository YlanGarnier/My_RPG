/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player.c
*/

#include "game.h"
#include "player.h"

static sfTexture *create_texture(int direction, int i)
{
    sfIntRect area;

    area.left = i * 77;
    area.top = direction * 77;
    area.width = 77;
    area.height = 77;
    return (sfTexture_createFromFile("assets/player/player.png", &area));
}

static sfTexture *create_sword_texture(int i)
{
    sfIntRect area;

    area.left = i * 120;
    area.top = 0;
    area.width = 120;
    area.height = 120;
    return (sfTexture_createFromFile("assets/player/sword_attack.png",
    &area));
}

void initialize_textures(void)
{
    for (int i = 0; i < 8; i++) {
        game()->player.sprites.moove_top[i] = create_texture(UP, i);
        game()->player.sprites.moove_bot[i] = create_texture(DOWN, i);
        game()->player.sprites.moove_left[i] = create_texture(LEFT, i);
        game()->player.sprites.moove_right[i] = create_texture(RIGHT, i);
    }
    for (int i = 0; i < 22; i++)
        game()->player.sprites.attack_sword[i] = create_sword_texture(i);
    sfSprite_setTexture(game()->player.sprite,
    game()->player.sprites.moove_bot[0], sfTrue);
    sfSprite_setTexture(game()->player.sword_sprite,
    game()->player.sprites.attack_sword[0], sfTrue);
    sfSprite_setOrigin(game()->player.sprite, (sfVector2f){37.5, 37.5});
    sfSprite_setOrigin(game()->player.sword_sprite, (sfVector2f){60, 60});
    sfSprite_setScale(game()->player.sprite, (sfVector2f){0.75 * ZOOM,
    0.75 * ZOOM});
    sfSprite_setScale(game()->player.sword_sprite, (sfVector2f){0.85 * ZOOM,
    0.85 * ZOOM});
    sfSprite_setPosition(game()->player.sprite, (sfVector2f){4952.0 * ZOOM,
    5694.0 * ZOOM});
}

sfTexture *choose_texture(int i)
{
    if (game()->player.direction == UP)
        return (game()->player.sprites.moove_top[i]);
    if (game()->player.direction == DOWN)
        return (game()->player.sprites.moove_bot[i]);
    if (game()->player.direction == LEFT)
        return (game()->player.sprites.moove_left[7 - i]);
    if (game()->player.direction == RIGHT)
        return (game()->player.sprites.moove_right[7 - i]);
    return (NULL);
}
