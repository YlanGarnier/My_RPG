/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy_stats.c
*/

#include "game.h"
#include "enemy.h"

void set_level(enemy_t *enemy, int level)
{
    enemy->stats.level = level;
    sfText_setString(enemy->ui.level, cat_text("Lvl ", my_itoa(level)));
}

void set_health(enemy_t *enemy, int health)
{
    float f_health = (float)health;
    float f_max_health = (float)enemy->stats.max_health;

    enemy->set_state(enemy, E_DAMAGE);
    if (health <= 0) {
        enemy->set_state(enemy, E_DEATH);
        f_health = 0.0;
    }
    enemy->stats.health = health;
    sfRectangleShape_setScale(enemy->ui.health_bar,
    (sfVector2f){f_health / f_max_health, 1});
}
