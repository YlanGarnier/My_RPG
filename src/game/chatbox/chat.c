/*
** EPITECH PROJECT, 2022
** chatbox
** File description:
** chatbox rpg
*/

#include <stdlib.h>
#include "../../../include/game.h"
#include "../../../include/chatbox.h"

int change_text(sfText *text, chat_t *chat)
{
    int s = chat->str_index;
    int l = chat->let_index;
    int len = get_textnlen(chat->strings[s], l + 1);
    char *str = NULL;

    if (chat->strings[s][l] == '\0')
        return 0;
    if (s > 0 && chat->strings[s][l] == '\\' &&
        chat->strings[s][l + 1] == 'n')
        ++chat->let_index;
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    fill_str(str, chat->strings[s], len);
    ++chat->let_index;
    sfText_setString(text, str);
    free(str);
    return 1;
}

int change_next_chat_index(chatbox_t *chatbox)
{
    if (chatbox->next_chat_index + 1 < chatbox->nb_chat)
        ++chatbox->next_chat_index;
    else
        chatbox->next_chat_index = 1;
    return 0;
}

int change_chat(chatbox_t *chatbox)
{
    if (chatbox->chat[chatbox->chat_index]->str_index == 2 ||
        chatbox->chat[chatbox->chat_index]->str_index == 3) {
        chatbox->chat[chatbox->chat_index]->str_index = 0;
        chatbox->chat[chatbox->chat_index]->let_index = 0;
        chatbox->choice = 0;
        chatbox->chat_index = -1;
        change_next_chat_index(chatbox);
        return 0;
    }
    if (chatbox->chat[chatbox->chat_index]->str_index == 0)
        chatbox->chat[chatbox->chat_index]->str_index = 1;
    else if (chatbox->chat[chatbox->chat_index]->str_index == 1) {
        if (chatbox->choice == 0)
            chatbox->chat[chatbox->chat_index]->str_index = 2;
        if (chatbox->choice == 1)
            chatbox->chat[chatbox->chat_index]->str_index = 3;
    }
    chatbox->chat[chatbox->chat_index]->let_index = 0;
    return 1;
}

sfText *set_text(sfFont *font, sfColor color, int size)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setFillColor(text, color);
    return text;
}

chat_t **set_chat(int *next_chat_index)
{
    chat_t **chat = NULL;
    char *buffer = my_readfile("config/msg.config");
    char **all_lines = my_str_to_word_array(buffer, '\n');
    char **line;
    int len = my_arraylen(all_lines);

    chat = malloc(sizeof(chat_t *) * (len + 1));
    chat[len] = NULL;
    next_chat_index[0] = len;
    for (int i = 0; i < len; ++i) {
        line = my_str_to_word_array(all_lines[i], '=');
        chat[i] = malloc(sizeof(chat_t));
        chat[i]->str_index = 0;
        chat[i]->let_index = 0;
        chat[i]->strings = my_str_to_word_array(line[1], '|');
        my_free_array(line);
    }
    my_free_array(all_lines);
    free(buffer);
    return chat;
}
