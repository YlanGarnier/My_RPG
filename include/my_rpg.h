/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** my_rpg.h
*/

#pragma once

#include "my.h"

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>

#define PI 3.14159
#define ZOOM 1.7

// UTILS

float get_delta_time(void);
char *cat_text(char *base, const char *to_add);
