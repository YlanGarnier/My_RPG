/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int temp_a = *a;
    int temp_b = *b;
    *a = temp_b;
    *b = temp_a;
}
