##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

LFLAGS=	-L./lib -lmy -lmy_getopt -lmy_fgets
ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LFLAGS+=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system
else
LFLAGS+=	-lc_graph_prog
endif

NAME=	my_runner

SRC_DIR=	$(realpath ./srcs)
SRC=		$(SRC_DIR)/main.c                                         \
			$(SRC_DIR)/map.c                                          \
			$(SRC_DIR)/game.c                                         \
			$(SRC_DIR)/init.c                                         \
			$(SRC_DIR)/colision.c                                     \
			$(SRC_DIR)/function_pointer.c                             \
			$(SRC_DIR)/ground/ground.c                                \
			$(SRC_DIR)/background/background.c                        \
			$(SRC_DIR)/death_screen/death_screen.c                    \
			$(SRC_DIR)/death_screen/death_title.c                     \
			$(SRC_DIR)/main_menu/menu.c                               \
			$(SRC_DIR)/main_menu/buttons.c                            \
			$(SRC_DIR)/main_menu/info_button.c                        \
			$(SRC_DIR)/main_menu/title.c                              \
			$(SRC_DIR)/info_btn/info_btn.c                            \
			$(SRC_DIR)/mob/mob.c                                      \
			$(SRC_DIR)/player/player.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my re
	make -C lib/my_fgets re
	make -C lib/my_getopt re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	make -C lib/my_fgets clean
	make -C lib/my_getopt clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/my_fgets fclean
	make -C lib/my_getopt fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
