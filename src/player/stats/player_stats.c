/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** player_stats.c
*/

#include "game.h"
#include "player.h"

void update(void);
void draw(void);
void set_point(int point);

static void initialize_stats_sprite(void)
{
    player_t *player = &game()->player;
    stats_menu_t *menu = &player->stats_menu;
    sfTexture *bg = sfTexture_createFromFile("assets/player/stats.png", NULL);
    sfVector2f origin = {316.5, 222.0};
    sfVector2f pos = {player->position.x + 300, player->position.y};
    sfVector2f scale = {0.65, 0.65};

    menu->background = sfSprite_create();
    sfSprite_setTexture(menu->background, bg, sfTrue);
    sfSprite_setOrigin(menu->background, origin);
    sfSprite_setPosition(menu->background, pos);
    sfSprite_setScale(menu->background, scale);
}

static void initialize_title_text(void)
{
    player_t *player = &game()->player;
    stats_menu_t *menu = &player->stats_menu;
    sfFont *font = sfFont_createFromFile("assets/fonts/pixel.ttf");

    menu->title = sfText_create();
    sfText_setFont(menu->title, font);
    sfText_setFillColor(menu->title, sfWhite);
    sfText_setOutlineColor(menu->title, sfBlack);
    sfText_setOutlineThickness(menu->title, 2.5);
    sfText_setCharacterSize(menu->title, 30);
    sfText_setString(menu->title, "Character");
    menu->stats_point = sfText_create();
    sfText_setFont(menu->stats_point, font);
    sfText_setFillColor(menu->stats_point, sfWhite);
    sfText_setOutlineColor(menu->stats_point, sfBlack);
    sfText_setOutlineThickness(menu->stats_point, 1.65);
    sfText_setCharacterSize(menu->stats_point, 20);
    sfText_setString(menu->stats_point, cat_text("Point : ",
    my_itoa(player->stats.stats_point)));
}

static void initialize_stats_text(sfText **text, char *name, int stat)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/pixel.ttf");

    *text = sfText_create();
    sfText_setFont(*text, font);
    sfText_setFillColor(*text, sfWhite);
    sfText_setOutlineColor(*text, sfBlack);
    sfText_setOutlineThickness(*text, 1.75);
    sfText_setCharacterSize(*text, 15);
    sfText_setString(*text, cat_text(name, my_itoa(stat)));
}

static void initialize_default_stats(void)
{
    player_t *player = &game()->player;

    player->stats.level = 1;
    player->stats.xp = 0;
    player->stats.max_xp = 100;
    player->stats.stats_point = 5;
    player->stats.health = 100;
    player->stats.max_health = 100;
    player->stats.speed = 20;
    player->stats.attack = 20;
    player->stats.defense = 10;
}

void initialize_stats(void)
{
    player_t *player = &game()->player;
    stats_menu_t *menu = &player->stats_menu;

    initialize_default_stats();
    initialize_stats_sprite();
    initialize_title_text();
    initialize_stats_text(&menu->health, "Health -> ",
    player->stats.max_health);
    initialize_stats_text(&menu->attack, "Attack -> ", player->stats.attack);
    initialize_stats_text(&menu->defense, "Defense -> ",
    player->stats.defense);
    initialize_stats_text(&menu->speed, "Speed -> ", player->stats.speed);
    initialize_stats_button();
    menu->open = 0;
    menu->update = update;
    menu->draw = draw;
    player->set_point = set_point;
}
