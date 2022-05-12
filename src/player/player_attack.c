/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_attack.c
*/

#include "game.h"
#include "player.h"

static void attack(void)
{
    player_t *player = &game()->player;
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(player->attack_box);
    enemy_t **enemies = game()->entities.enemies;
    enemy_t *enemy;
    sfFloatRect enemy_rect;
    int defense;
    srand(time(NULL));
    player->attacking = 1;
    sfClock_restart(player->attack_clock);
    for (int i = 0; enemies[i] != NULL; i++) {
        enemy = enemies[i];
        if (enemy->stats.health <= 0) continue;
        enemy_rect = sfSprite_getGlobalBounds(enemy->sprite);
        if (sfFloatRect_intersects(&rect, &enemy_rect, NULL)) {
            defense = rand() % enemy->stats.defense;
            enemy->set_health(enemy,
            enemy->stats.health - (player->stats.attack - defense));
        }
        enemies = game()->entities.enemies;
    }
}

void initialize_attack(void)
{
    game()->player.attack = attack;
}
