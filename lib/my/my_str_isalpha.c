/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_str_isalpha
*/

static int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_alpha(str[i]) == 0)
            return 0;
    }
    return 1;
}
