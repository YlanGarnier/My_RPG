/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strcmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    for (; s1[i] == s2[i] && i < n - 1; i += 1) {
        if (s1[i] == '\0')
            return s1[i] - s2[i];
    }
    return s1[i] - s2[i];
}
