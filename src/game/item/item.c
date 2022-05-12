/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** item.c
*/

#include "game.h"
#include "item.h"

static void initialize_item(char **items, int id)
{
    stats_t *s = &game()->player.stats;
    const int *stats[4] = {&s->health, &s->speed, &s->attack, &s->defense};
    item_t *item = &game()->items[id];
    char **item_data = my_str_to_word_array(items[id], ';');
    sfTexture *item_text = sfTexture_createFromFile(cat_text("assets/items/",
    item_data[2]), NULL);

    item->id = id;
    item->name = my_strdup(item_data[0]);
    item->description = my_strdup(item_data[1]);
    item->sprite = sfSprite_create();
    sfSprite_setTexture(item->sprite, item_text, sfTrue);
    sfSprite_setOrigin(item->sprite, (sfVector2f){8, 8});
    if (my_getnbr(item_data[3]) == -1) {
        item->stat = NULL;
    } else {
        item->stat = stats[my_getnbr(item_data[3])];
        item->add_value = my_getnbr(item_data[4]);
    }
}

void initialize_items(void)
{
    char *item_file = my_readfile("config/items.config");
    char **items = my_str_to_word_array(item_file, '\n');
    int item_count = my_arraylen(items);

    game()->items = malloc(sizeof(struct item) * (item_count + 1));
    game()->items[item_count].id = -1;
    for (int i = 0; i < item_count; i++)
        initialize_item(items, i);
}
