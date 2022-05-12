/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strupcase
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}
