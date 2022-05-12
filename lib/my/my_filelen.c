/*
** EPITECH PROJECT, 2022
** my_filelen
** File description:
** get size of a file and return it
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int my_filelen(char const *path)
{
    int len = -1;
    struct stat buf;

    if (stat(path, &buf) == -1)
        return -1;
    len = buf.st_size;
    return len;
}
