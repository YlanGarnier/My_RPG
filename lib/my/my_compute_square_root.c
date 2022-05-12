/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    for (int i = 0; i <= nb; i++) {
        if (i * i == nb)
            return i;
    }
    return (0);
}
