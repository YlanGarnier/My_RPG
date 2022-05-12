/*
** EPITECH PROJECT, 2022
** my_readfile
** File description:
** read a file and return his content
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int my_filelen(char const *);

char *my_readfile(char const *path)
{
    int fd;
    int size;
    char *content = NULL;

    if ((size = my_filelen(path)) <= 0)
        return NULL;
    if ((fd = open(path, O_RDONLY)) == -1)
        return NULL;
    if ((content = malloc(sizeof(char) * (size + 1))) == NULL) {
        close(fd);
        return NULL;
    }
    content[size] = '\0';
    if (read(fd, content, size) == -1) {
        free(content);
        content = NULL;
    }
    close(fd);
    return content;
}
