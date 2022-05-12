/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy_spawn.c
*/

#include "game.h"
#include "enemy.h"

int get_last_id(void);
void initialize_enemy(enemy_t *enemy);

void kill_enemy(enemy_t *enemy)
{
    player_t *player = &game()->player;
    entities_t *entities = &game()->entities;

    player->set_xp(player->stats.xp + enemy->stats.xp_reward);
    sfClock_destroy(enemy->clock);
    sfSprite_destroy(enemy->sprite);
    sfRectangleShape_destroy(enemy->ui.health_bar);
    sfRectangleShape_destroy(enemy->ui.health_bar_bg);
    sfText_destroy(enemy->ui.level);
    free(enemy->name);
    entities->remove_enemy(&entities->enemies, enemy);
    free(enemy);
}

enemy_t *spawn_enemy(int type, sfVector2f pos)
{
    enemy_t *template = &game()->enemies[type];
    enemy_t *enemy = malloc(sizeof(struct enemy));
    entities_t *entities = &game()->entities;

    enemy->id = game()->entities.enemies[0] == NULL ? 0 : get_last_id() + 1;
    enemy->type = type;
    enemy->state = E_IDLE;
    enemy->direction = E_DOWN;
    enemy->name = my_strdup(template->name);
    enemy->stats = template->stats;
    enemy->clock = sfClock_create();
    enemy->sprite = sfSprite_copy(template->sprite);
    sfSprite_setPosition(enemy->sprite, pos);
    initialize_enemy_ui(enemy);
    initialize_enemy(enemy);
    entities->push_enemy(&entities->enemies, enemy);
    return (enemy);
}
