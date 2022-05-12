/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** enemy_textures.c
*/

#include "game.h"
#include "enemy.h"

const char *dir_name[4] = {"/Down/", "/Left/", "/Right/", "/Up/"};

static void initialize_enemy_texture(enemy_t *enemy,
char **enemy_data, int dir)
{
    char *enemy_path = cat_text("assets/enemies/", enemy_data[7]);
    char *path = cat_text(enemy_path, dir_name[dir]);
    DIR *directory = opendir(path);
    struct dirent *dirp;
    char **texture_data, **texture_rect;
    enemy_textures_t *t = &enemy->textures;
    enemy_rect_t *r = &enemy->rect;
    sfTexture **ts[5] = {t->attack, t->damage, t->death, t->idle, t->movement};
    sfVector3f *rs[5] = {r->attack, r->damage, r->death, r->idle, r->movement};
    int state = 0;
    while ((dirp = readdir(directory)) != NULL) {
        if (dirp->d_name[0] == '.') continue;
        texture_data = my_str_to_word_array(dirp->d_name, '_');
        texture_rect = my_str_to_word_array(texture_data[1], 'x');
        ts[state][dir] = sfTexture_createFromFile(cat_text(path, dirp->d_name),
        NULL);
        rs[state][dir].x = my_getnbr(texture_rect[0]);
        rs[state][dir].y = my_getnbr(texture_rect[1]);
        rs[state++][dir].z = my_getnbr(texture_rect[2]);
    }
}

void initialize_enemy_textures(enemy_t *enemy,
char **enemy_data)
{
    for (int i = 0; i < 4; i++)
        initialize_enemy_texture(enemy, enemy_data, i);
}
