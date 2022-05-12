/*
** EPITECH PROJECT, 2021
** day8
** File description:
** convert_base
*/

#include "my.h"
#include <stdlib.h>

static char convert_nbr_to_char(int nbr)
{
    return nbr + 87;
}

static int to_base_ten(int i_nbr, int i_base_from)
{
    int nbr_base_ten = 0;
    int nb_digits = 0;
    int temp_nbr = i_nbr;
    int modulo = 10;
    int *digits;
    while (temp_nbr >= 1) {
        temp_nbr /= 10;
        nb_digits += 1;
    }
    digits = malloc(sizeof(int) * nb_digits);
    for (int i = 0; i < nb_digits; i += 1) {
        digits[i] = (i_nbr % modulo) / (modulo / 10);
        modulo *= 10;
    }
    nbr_base_ten = digits[nb_digits - 1];
    for (int i = nb_digits - 2; i >= 0; i -= 1)
        nbr_base_ten = nbr_base_ten * i_base_from + digits[i];
    free(digits);
    return nbr_base_ten;
}

static int *ten_to_base_n(int *i, int n2, int i_base_to)
{
    int *digits;
    int q = n2;
    int temp_q = q;
    while (temp_q > 0) {
        temp_q = temp_q / i_base_to;
        *i += 1;
    }
    digits = malloc(sizeof(int) * (*i));
    *i = 0;
    while (q > 0) {
        digits[*i] = q % i_base_to;
        q = q / i_base_to;
        *i += 1;
    }
    return digits;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int i_nbr = my_getnbr(nbr);
    int i_base_from = my_getnbr(base_from);
    int i_base_to = my_getnbr(base_to);
    int nbr_base_ten = 0;
    int i = 0;
    int *digits;
    nbr_base_ten = to_base_ten(i_nbr, i_base_from);
    digits = ten_to_base_n(&i, nbr_base_ten, i_base_to);
    char *result = malloc(sizeof(char) * i + 1);
    result[i] = '\0';
    for (int j = 0; j < i; j += 1) {
        if (digits[i - j - 1] > 9)
            result[j] = convert_nbr_to_char(digits[i - j - 1]);
        else
            result[j] = digits[i - j - 1] + '0';
    }
    free(digits);
    return result;
}
