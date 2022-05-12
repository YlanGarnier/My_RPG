/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    if (nb == 0 || nb == 1 || nb < 0)
        return (0);
    for (int j = 2; j <= nb; j++) {
        if (nb % j == 0 && j != nb)
            return (0);
    }
    return (1);
}
