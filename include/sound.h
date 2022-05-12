/*
** EPITECH PROJECT, 2022
** sound.h
** File description:
** let's groove
*/

#pragma once

#include "game.h"

typedef struct sound_s {
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

void initialize_sounds(void);
