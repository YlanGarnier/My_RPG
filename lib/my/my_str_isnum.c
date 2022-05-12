/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_str_isalpha
*/

static int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_num(str[i]) == 0)
            return 0;
    }
    return 1;
}
