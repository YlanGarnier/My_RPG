/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return str;
}
