/*
** EPITECH PROJECT, 2022
** menu_sound.c
** File description:
** set sound
*/

#include "game.h"
#include "sound.h"

void reduce_sound(sfRectangleShape *rect)
{
    sfVector2f size = sfRectangleShape_getSize(rect);
    sound_t *sounds = game()->sounds;
    float volume = sfMusic_getVolume(sounds[0].music);

    if (size.x > 0) {
        size.x -= 12;
        volume -= 10;
        sfMusic_setVolume(sounds[0].music, volume);
        sfMusic_setVolume(sounds[1].music, volume);
        sfRectangleShape_setSize(rect, size);
    }
}

void increase_sound(sfRectangleShape *rect)
{
    sfVector2f size = sfRectangleShape_getSize(rect);
    sound_t *sounds = game()->sounds;
    float volume = sfMusic_getVolume(sounds[0].music);

    if (size.x < 120) {
        size.x += 12;
        volume += 10;
        sfMusic_setVolume(sounds[0].music, volume);
        sfMusic_setVolume(sounds[1].music, volume);
        sfRectangleShape_setSize(rect, size);
    }
}
