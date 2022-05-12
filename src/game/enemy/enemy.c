/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy.c
*/

#include "game.h"
#include "enemy.h"

static void initialize_sprite(enemy_t *enemy)
{
    sfIntRect rect = {0, 0, enemy->rect.idle[0].y, enemy->rect.idle[0].z};
    sfVector2f origin = {enemy->rect.idle[0].y / 2, enemy->rect.idle[0].z};
    sfVector2f scale = {1.5 * ZOOM, 1.5 * ZOOM};

    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite, enemy->textures.idle[0], sfTrue);
    sfSprite_setTextureRect(enemy->sprite, rect);
    sfSprite_setOrigin(enemy->sprite, origin);
    sfSprite_setScale(enemy->sprite, scale);
}

static void initialize_enemy(char **enemies, int type)
{
    enemy_t *enemy = &game()->enemies[type];
    char **enemy_data = my_str_to_word_array(enemies[type], ';');

    enemy->id = 0;
    enemy->type = type;
    enemy->name = my_strdup(enemy_data[0]);
    enemy->stats.speed = my_getnbr(enemy_data[1]);
    enemy->stats.health = my_getnbr(enemy_data[2]);
    enemy->stats.max_health = my_getnbr(enemy_data[2]);
    enemy->stats.attack = my_getnbr(enemy_data[3]);
    enemy->stats.defense = my_getnbr(enemy_data[4]);
    enemy->stats.level = my_getnbr(enemy_data[5]);
    enemy->stats.xp_reward = my_getnbr(enemy_data[6]);
    initialize_enemy_textures(enemy, enemy_data);
    initialize_sprite(enemy);
}

void initialize_enemies(void)
{
    char *enemy_file = my_readfile("config/enemies.config");
    char **enemies = my_str_to_word_array(enemy_file, '\n');
    int enemy_count = my_arraylen(enemies);

    game()->enemies = malloc(sizeof(struct enemy) * (enemy_count + 1));
    game()->enemies[enemy_count].id = -1;
    for (int i = 0; i < enemy_count; i++)
        initialize_enemy(enemies, i);
}
