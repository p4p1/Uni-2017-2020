##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -I./include

LFLAGS= -g3 -L./lib -lmy -lmy_getopt -lmy_fgets -lncurses

NAME=	my_sokoban

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c                                        \
			$(SRC_DIR)/init.c                                        \
			$(SRC_DIR)/event.c                                       \
			$(SRC_DIR)/player.c                                      \
			$(SRC_DIR)/get_map.c                                     \
			$(SRC_DIR)/get_box.c                                     \
			$(SRC_DIR)/box.c                                         \
			$(SRC_DIR)/destroy.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my/ re
	make -C lib/my_fgets/ re
	make -C lib/my_getopt/ re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my/ clean
	make -C lib/my_fgets/ clean
	make -C lib/my_getopt/ clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my/ fclean
	make -C lib/my_fgets/ fclean
	make -C lib/my_getopt/ fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
