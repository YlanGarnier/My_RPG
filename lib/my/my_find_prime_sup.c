/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = nb;
    while (my_is_prime(i) != 1)
        i++;
    return i;
}
