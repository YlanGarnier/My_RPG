/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** item.h
*/

#pragma once

#include "my_rpg.h"

enum item_type {
    HEALTH_POTION,
    GREAT_HEALTH_POTION,
    SPEED_POTION,
    GREAT_SPEED_POTION,
    ATTACK_SCROLLS,
    DEFENSE_SCROLLS,
    KEY,
    APPLE,
    CHEESE
};

typedef struct item {
    int id;
    sfSprite *sprite;
    char *name;
    char *description;
    int *stat;
    int add_value;
} item_t;

void initialize_items(void);
