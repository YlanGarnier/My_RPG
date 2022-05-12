##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

PLAYER_PATH = src/player/

GAME_PATH = src/game/

MENU_PATH = src/menu/

SRCS	=	src/my_rpg.c \
			$(GAME_PATH)game.c \
			$(GAME_PATH)map/map_tools.c \
			$(GAME_PATH)map/map_layers.c \
			$(GAME_PATH)map/set_map_infos.c	\
			$(GAME_PATH)map/map_set_collisions.c \
			$(GAME_PATH)map/map.c \
			$(GAME_PATH)item/item.c \
			$(GAME_PATH)enemy/enemy.c \
			$(GAME_PATH)enemy/enemy_textures.c \
			$(GAME_PATH)enemy/enemy_spawn.c \
			$(GAME_PATH)enemy/enemy_utils.c \
			$(GAME_PATH)enemy/enemy_manager.c \
			$(GAME_PATH)enemy/enemy_animation.c \
			$(GAME_PATH)enemy/enemy_movement.c \
			$(GAME_PATH)enemy/enemy_ui.c \
			$(GAME_PATH)enemy/enemy_stats.c \
			$(GAME_PATH)enemy/spawner.c \
			$(GAME_PATH)entities/entities.c \
			$(GAME_PATH)entities/entities_utils.c \
			$(MENU_PATH)menu_background.c \
			$(MENU_PATH)menu_button.c \
			$(MENU_PATH)menu_event.c \
			$(MENU_PATH)menu.c \
			$(MENU_PATH)menu_sound.c \
			$(MENU_PATH)menu_initialize.c \
			$(MENU_PATH)menu_fps.c \
			$(PLAYER_PATH)player.c \
			$(PLAYER_PATH)player_attack.c \
			$(PLAYER_PATH)player_textures.c \
			$(PLAYER_PATH)player_animation.c \
			$(PLAYER_PATH)player_event.c \
			$(PLAYER_PATH)player_movement.c \
			$(PLAYER_PATH)player_health.c \
			$(PLAYER_PATH)player_xp.c \
			$(PLAYER_PATH)player_camera.c \
			$(PLAYER_PATH)player_position.c \
			$(PLAYER_PATH)player_hitbox.c \
			$(PLAYER_PATH)player_collisions.c \
			$(PLAYER_PATH)player_interaction_chest.c \
			$(PLAYER_PATH)player_interaction_dungeon.c \
			$(PLAYER_PATH)player_interaction_pnj.c \
			$(PLAYER_PATH)player_ui.c \
			$(PLAYER_PATH)stats/player_stats.c \
			$(PLAYER_PATH)stats/player_stats_manager.c \
			$(PLAYER_PATH)stats/player_stats_button.c \
			$(PLAYER_PATH)inventory/player_inventory.c \
			$(PLAYER_PATH)inventory/player_item.c \
			$(PLAYER_PATH)inventory/player_slot.c \
			src/menu_ig/event.c	\
			src/menu_ig/menu_ig.c \
			src/sounds/initialize_sounds.c \
			src/game/chatbox/box.c	\
			src/game/chatbox/chat.c	\
			src/game/chatbox/chatbox_tools.c	\
			src/game/chatbox/chatbox.c	\
			src/window/window.c \
			src/window/event.c \
			src/save/save.c \
			src/save/load_save.c \
			src/utils.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_rpg

LIB	=	lib/libmy.a

CC	=	gcc

LDFLAGS	=	-L lib/my -lmy

CPPFLAGS	=	-I include/ -lm

CFLAGS	=	-Wall -Wextra

CSMLFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

RM	=	rm -rf

all:	$(LIB) $(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS) $(CPPFLAGS) $(CSMLFLAGS)

$(LIB):
	make -C lib/my/

clean:
	$(RM) $(OBJS)

fclean: clean
	make fclean -C lib/my/
	$(RM) $(NAME)

re: fclean all

.PHONY	=	all clean fclean re
