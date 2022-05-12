/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** entities.c
*/

#include "game.h"
#include "entities.h"

int get_index(enemy_t **array, enemy_t *current);
int get_size(enemy_t **array);
int count_enemy(void);

static void push_enemy(enemy_t ***array, enemy_t *element)
{
    int size = get_size(*array);
    enemy_t **new = malloc((size + 2) * sizeof(struct enemy *));

    new[size + 1] = NULL;
    for (int i = 0; i < size; i++)
        new[i] = (*array)[i];
    new[size] = element;
    free(*array);
    *array = new;
}

static void remove_enemy(enemy_t ***array, enemy_t *element)
{
    int index = get_index(*array, element);
    int size = get_size(*array);
    enemy_t **new = malloc((size) * sizeof(struct enemy *));
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (i == index) continue;
        new[j] = (*array)[i];
        j++;
    }
    new[size - 1] = NULL;
    free(*array);
    *array = new;
}

static void update(void)
{
    enemy_t **enemies = game()->entities.enemies;
    int enemy_count;

    for (int i = 0; enemies[i] != NULL; i++) {
        enemy_count = count_enemy();
        enemies[i]->update(enemies[i]);
        enemies = game()->entities.enemies;
        if (enemy_count > count_enemy())
            i--;
    }
}

static void draw(void)
{
    enemy_t **enemies = game()->entities.enemies;

    for (int i = 0; enemies[i] != NULL; i++) {
        enemies[i]->draw(enemies[i]);
        enemies = game()->entities.enemies;
    }
}

void initialize_entities(void)
{
    game()->entities.enemies = malloc(sizeof(struct enemy *));
    game()->entities.enemies[0] = NULL;
    game()->entities.update = update;
    game()->entities.draw = draw;
    game()->entities.push_enemy = push_enemy;
    game()->entities.remove_enemy = remove_enemy;
}
