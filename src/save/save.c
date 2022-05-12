/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** save.c
*/

#include "game.h"
#include "save.h"
#include "player.h"

static char *get_pos(void)
{
    player_t *player = &game()->player;
    char *pos = my_itoa(player->position.x);

    pos = cat_text(pos, " ");
    pos = cat_text(pos, my_itoa(player->position.y));
    pos = cat_text(pos, "|");
    return (pos);
}

static char *get_stats(void)
{
    stats_t *p_stats = &game()->player.stats;
    char *stats = my_itoa(p_stats->level);

    stats = cat_text(cat_text(stats, ","), my_itoa(p_stats->xp));
    stats = cat_text(cat_text(stats, ","), my_itoa(p_stats->max_xp));
    stats = cat_text(cat_text(stats, ","), my_itoa(p_stats->stats_point));
    stats = cat_text(cat_text(stats, ","), my_itoa(p_stats->health));
    stats = cat_text(cat_text(stats, ","), my_itoa(p_stats->max_health));
    stats = cat_text(cat_text(stats, ","), my_itoa(p_stats->speed));
    stats = cat_text(cat_text(stats, ","), my_itoa(p_stats->attack));
    stats = cat_text(cat_text(stats, ","), my_itoa(p_stats->defense));
    stats = cat_text(stats, "|");
    return (stats);
}

static char *get_inventory(void)
{
    inventory_t *inv = &game()->player.inventory;
    char *inventory = "";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            inventory = cat_text(inventory, inv->slots[i][j].empty ? "-1"
            : my_itoa(inv->slots[i][j].item->id));
            inventory = cat_text(inventory, j != 6 ? "," : "\n");
        }
    }
    return (inventory);
}

void save_game(char *file)
{
    int fd = open(file, O_RDWR);
    char *save = "";

    if (fd == -1)
        return;
    save = cat_text(save, get_pos());
    save = cat_text(save, get_stats());
    save = cat_text(save, get_inventory());
    write(fd, save, my_strlen(save));
    close(fd);
}
