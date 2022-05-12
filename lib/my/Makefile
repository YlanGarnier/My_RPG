##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

INCLUDE	=	.

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	copyheader fclean $(OBJ) $(NAME) copylib clean

copyheader:
	cp my.h ../../include/my.h

$(OBJ):		$(SRC)
	gcc -c $(SRC) -I $(INCLUDE)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

copylib:
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:
	rm -f ../$(NAME)
