/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int nbr = 0;
    int neg = 1;
    long temp = 0;
    for (; str[nbr] == '+' || str[nbr] == '-'; nbr++) {
        if (str[nbr] == '-')
            neg = neg * (-1);
    }
    for (; str[nbr] >= '0' && str[nbr] <= '9'; nbr++) {
        temp = temp + str[nbr] - 48;
        temp = temp * 10;
        if (neg * temp / 10 < -2147483648 || neg * temp / 10 > 2147483647)
            return (0);
    }
    nbr = neg * temp / 10;
    return nbr;
}
