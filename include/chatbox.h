/*
** EPITECH PROJECT, 2022
** chatbox
** File description:
** all functions and struct about chatbox
*/

#pragma once

#include "player.h"
#include "window.h"

typedef struct chat_s {
    int str_index;
    int let_index;
    char **strings;
} chat_t;

typedef struct chatbox_s {
    int nb_chat;
    int next_chat_index;
    int chat_index;
    sfClock *clock;
    float speed;
    int choice;
    sfRectangleShape *box;
    sfRectangleShape *arrow;
    chat_t **chat;
    sfFont *font;
    sfText *text;
    sfText *instruction;
    void (*event)(window_t *window, struct chatbox_s *chatbox, int *state);
    void (*update)(struct chatbox_s *chatbox, window_t *window,
    player_t *player);
    void (*destroy)(struct chatbox_s *chatbox);
} chatbox_t;

int get_textnlen(char *str, int n);
int fill_str(char *dest, char *src, int len);
void update_pos(chatbox_t *chatbox, window_t *window, sfVector2f player_pos);
sfRectangleShape *set_arrow(void);
void set_box(chatbox_t *chatbox);
int change_text(sfText *text, chat_t *chat);
int change_chat(chatbox_t *chatbox);
sfText *set_text(sfFont *font, sfColor color, int size);
chat_t **set_chat(int *next_chat_index);
chatbox_t init_chatbox(window_t *window, player_t *player);
