/*
** EPITECH PROJECT, 2021
** day9
** File description:
** get_color
*/

#include "my.h"

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int i_red = red << 16;
    int i_green = green << 8;
    int i_blue = blue;
    return i_red + i_green + i_blue;
}
