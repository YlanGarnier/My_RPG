/*
** EPITECH PROJECT, 2021
** day7
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #define ABS(x) (x > 0 ? x : x * (-1))

    #include <stdarg.h>

typedef struct flag {
    char type;
    void (*func)(va_list);
} flag_t;

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
void my_print_params(int, char **);
void my_rev_params(int, char **);
void my_sort_params(int, char **);
char *concat_params(int, char **);
char *my_strdup(char const *);
int my_show_word_array(char * const *);
char **my_str_to_word_array(char const *, char const);
char *convert_base(char const *, char const *, char const *);
int get_color(unsigned char, unsigned char, unsigned char);
int my_sort_word_array(char **);
int my_advanced_sort_word_array(char **, int(*)(char const *, char const *));
int my_printf(char const *format, ...);
char *my_itoa(int);
char char_to_hex(int);
int my_filelen(char const *);
char *my_readfile(char const *);
int my_arraylen(char **);
void my_free_array(char **);

#endif
