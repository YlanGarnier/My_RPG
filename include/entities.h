/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy.h
*/

#pragma once

#include "my_rpg.h"
#include "enemy.h"

typedef struct entities_t {
    enemy_t **enemies;
    void (*update)(void);
    void (*draw)(void);
    void (*push_enemy)(enemy_t ***array, enemy_t *element);
    void (*remove_enemy)(enemy_t ***array, enemy_t *element);
} entities_t;

void initialize_entities(void);
