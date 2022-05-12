/*
** EPITECH PROJECT, 2022
** chatbox
** File description:
** chatbox rpg
*/

#include <stdlib.h>
#include "player.h"
#include "window.h"
#include "chatbox.h"

static void destroy(chatbox_t *chatbox)
{
    for (int i = 0; chatbox->chat[i] != NULL; ++i) {
        my_free_array(chatbox->chat[i]->strings);
        free(chatbox->chat[i]);
    }
    free(chatbox->chat);
    sfClock_destroy(chatbox->clock);
    sfRectangleShape_destroy(chatbox->box);
    sfRectangleShape_destroy(chatbox->arrow);
    sfFont_destroy(chatbox->font);
    sfText_destroy(chatbox->text);
    sfText_destroy(chatbox->instruction);
}

static void event(window_t *window, chatbox_t *chatbox, int *state)
{
    if (chatbox->chat_index == -1 && window->event.key.code == sfKeyEscape)
        state[0] = 2;
    if (chatbox->chat_index == -1)
        return;
    if (window->event.key.code == sfKeyE)
        change_chat(chatbox);
    if (chatbox->choice == 0 && window->event.key.code == sfKeyS)
        chatbox->choice = 1;
    else if (chatbox->choice == 1 && window->event.key.code == sfKeyZ)
        chatbox->choice = 0;
}

static void update(chatbox_t *chatbox, window_t *window, player_t *player)
{
    float time;

    if (chatbox->chat_index == -1)
        return;
    time = sfClock_getElapsedTime(chatbox->clock).microseconds / 1000000.0;
    update_pos(chatbox, window, player->position);
    if (time >= chatbox->speed) {
        change_text(chatbox->text, chatbox->chat[chatbox->chat_index]);
        sfClock_restart(chatbox->clock);
    }
    sfRenderWindow_drawRectangleShape(window->sf_window, chatbox->box, NULL);
    sfRenderWindow_drawText(window->sf_window, chatbox->text, NULL);
    sfRenderWindow_drawText(window->sf_window, chatbox->instruction, NULL);
    if (chatbox->chat[chatbox->chat_index]->str_index == 1) {
        sfRenderWindow_drawRectangleShape(window->sf_window,
        chatbox->arrow, NULL);
    }
}

chatbox_t init_chatbox(window_t *window, player_t *player)
{
    chatbox_t chatbox;

    chatbox.next_chat_index = 0;
    chatbox.chat_index = 0;
    chatbox.speed = 0.001;
    chatbox.choice = 0;
    chatbox.clock = sfClock_create();
    chatbox.chat = set_chat(&chatbox.nb_chat);
    set_box(&chatbox);
    chatbox.arrow = set_arrow();
    chatbox.font = sfFont_createFromFile("assets/fonts/chat.ttf");
    chatbox.text = set_text(chatbox.font, sfWhite, 28);
    chatbox.instruction = set_text(chatbox.font, sfWhite, 18);
    sfText_setString(chatbox.instruction, "Press 'E' to continue");
    update_pos(&chatbox, window, player->position);
    chatbox.event = event;
    chatbox.update = update;
    chatbox.destroy = destroy;
    return chatbox;
}
