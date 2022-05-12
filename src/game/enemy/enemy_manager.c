/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy_manager.c
*/

#include "game.h"
#include "enemy.h"

void animate(enemy_t *enemy);
void move(enemy_t *enemy);
void pathfind(enemy_t *enemy);
void set_state(enemy_t *enemy, int state);
void set_direction(enemy_t *enemy, int direction);
void set_level(enemy_t *enemy, int level);
void set_health(enemy_t *enemy, int health);

static void update(enemy_t *enemy)
{
    e_ui_t *ui = &enemy->ui;

    enemy->velocity = (sfVector2f){0.0, 0.0};
    ui->update(enemy);
    enemy->pathfind(enemy);
    enemy->move(enemy);
    enemy->animate(enemy);
}

static void draw(enemy_t *enemy)
{
    sfRenderWindow *window = game()->window.sf_window;
    e_ui_t *ui = &enemy->ui;

    sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
    ui->draw(enemy);
}

void initialize_enemy(enemy_t *enemy)
{
    enemy->update = update;
    enemy->draw = draw;
    enemy->animate = animate;
    enemy->move = move;
    enemy->pathfind = pathfind;
    enemy->set_state = set_state;
    enemy->set_direction = set_direction;
    enemy->set_level = set_level;
    enemy->set_health = set_health;
}
