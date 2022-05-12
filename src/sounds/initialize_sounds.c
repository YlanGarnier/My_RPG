/*
** EPITECH PROJECT, 2022
** initialize_sounds.c
** File description:
** create musics
*/

#include "game.h"
#include "sound.h"

void initialize_sounds(void)
{
    game()->sounds = malloc(sizeof(sound_t) * 4);
    sound_t *sounds = game()->sounds;
    sounds[0].music = sfMusic_createFromFile("sounds/menu.ogg");
    sounds[1].music = sfMusic_createFromFile("sounds/music.ogg");
    sounds[2].buffer = sfSoundBuffer_createFromFile("sounds/chest.ogg");
    sounds[3].buffer = sfSoundBuffer_createFromFile("sounds/sword.ogg");
    sounds[2].sound = sfSound_create();
    sounds[3].sound = sfSound_create();
    sfSound_setBuffer(sounds[2].sound, sounds[2].buffer);
    sfSound_setBuffer(sounds[3].sound, sounds[3].buffer);
    sfMusic_setLoop(sounds[0].music, sfTrue);
    sfMusic_setLoop(sounds[1].music, sfTrue);
    sfMusic_play(sounds[0].music);
}
