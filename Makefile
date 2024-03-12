##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	src/main.c						\
			src/check_env.c					\
			src/creations.c					\
			src/set_window.c				\
			src/event/event.c				\
			src/draw_entities.c				\
			src/initializations.c			\
			src/free_and_destroy.c			\
			src/set/set_shapes.c			\
			src/set/set_image_pixel.c		\
			src/event/resize_window.c		\
			src/event/buttons_hover.c		\
			src/event/buttons_actions.c		\
			src/event/buttons_clicked.c		\
			src/colors/set_shades.c			\
			src/colors/set_other_colors.c	\
			src/colors/set_primary_colors.c	\

OBJ     =	$(SRC:.c=.o)

NAME    =	my_paint

LIB		=	lib/libmy.a

CFLAGS	= 	-Wall -Wextra

CPPFLAGS	=	-I./include

LDFLAGS	=	-lmy -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio \
-lm

LDLIBS	=	-L./lib

all:    $(NAME)

$(LIB):
	make -C ./lib/my

$(NAME):	$(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(LDFLAGS)

debug:	CFLAGS += -gdb3

debug:	re

style:
		coding-style . .
		cat coding-style-reports.log
		rm -rf coding-style-reports.log

clean:
	$(RM) $(OBJ)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	make -C ./lib/my fclean

re:	fclean $(NAME)

.PHONY: all clean fclean re debug
