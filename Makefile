##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	src/main.c	\
			src/free_variable.c	\
			src/draw_entities.c	\
			src/set_window.c	\
			src/event.c	\
			src/init_variable.c	\

OBJ     =	$(SRC:.c=.o)

NAME    =	my_paint

LIB		=	lib/libmy.a

CFLAGS	= 	-Wall -Wextra

CPPFLAGS	=	-I./include

LDFLAGS	=	-lmy -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

LDLIBS	=	-L./lib

all:    $(NAME)

$(LIB):
	make -C ./lib/my

$(NAME):	$(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(LDFLAGS)

debug: CFLAGS += -gdb3
debug: re

clean:
	$(RM) $(OBJ)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	make -C ./lib/my fclean

re:	fclean $(NAME)

.PHONY: all clean fclean re debug
