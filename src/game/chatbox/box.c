/*
** EPITECH PROJECT, 2022
** box
** File description:
** box
*/

#include "../../../include/my_rpg.h"
#include "game.h"

sfRectangleShape *set_arrow(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(
        "assets/chatbox/arrow.png", NULL);
    sfVector2f arrow_size = {28, 20};

    sfRectangleShape_setSize(shape, arrow_size);
    sfRectangleShape_setTexture(shape, texture, sfFalse);
    return shape;
}

void set_box(chatbox_t *chatbox)
{
    sfTexture *texture = sfTexture_createFromFile(
        "assets/chatbox/box.png", NULL);

    chatbox->box = sfRectangleShape_create();
    sfRectangleShape_setSize(chatbox->box, (sfVector2f) {700, 150});
    sfRectangleShape_setTexture(chatbox->box, texture, sfFalse);
    return;
}
