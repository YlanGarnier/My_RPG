/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** load_save.c
*/

#include "game.h"
#include "save.h"
#include "player.h"

static void load_inventory(char **inventory_data)
{
    char **rows;

    for (int i = 0; i < 5; i++) {
        rows = my_str_to_word_array(inventory_data[i], ',');
        for (int j = 0; j < 7; j++)
            add_item(my_getnbr(rows[j]));
    }
}

void load_save(char *file)
{
    player_t *player = &game()->player;
    stats_t *stats = &player->stats;
    char *save = my_readfile(file);
    char **data = my_str_to_word_array(save, '|');
    char **pos_data = my_str_to_word_array(data[0], ' ');
    char **stats_data = my_str_to_word_array(data[1], ',');
    char **inventory_data = my_str_to_word_array(data[2], '\n');

    sfSprite_setPosition(player->sprite,
    (sfVector2f){my_getnbr(pos_data[0]), my_getnbr(pos_data[1])});
    stats->level = my_getnbr(stats_data[0]);
    stats->max_xp = my_getnbr(stats_data[2]);
    player->set_xp(my_getnbr(stats_data[1]));
    player->set_point(my_getnbr(stats_data[3]));
    stats->max_health = my_getnbr(stats_data[5]);
    player->set_health(my_getnbr(stats_data[4]));
    stats->speed = my_getnbr(stats_data[6]);
    stats->attack = my_getnbr(stats_data[7]);
    stats->defense = my_getnbr(stats_data[8]);
    load_inventory(inventory_data);
}
