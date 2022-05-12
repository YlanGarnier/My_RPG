/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_str_isprintable
*/

static int is_inascii(char c)
{
    if (c >= 32 && c <= 127)
        return 1;
    return 0;
}

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_inascii(str[i]) == 0)
            return 0;
    }
    return 1;
}
