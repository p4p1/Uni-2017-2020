##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -I./include

LFLAGS=	-L./lib -lmy -lcsfml-audio -lcsfml-window -lcsfml-graphics -lcsfml-system -lmy_getopt

NAME=	my_hunter

SRC_DIR=	$(realpath ./srcs)
SRC=		$(SRC_DIR)/main.c                                   \
			$(SRC_DIR)/init.c                                   \
			$(SRC_DIR)/destroy.c                                \
			$(SRC_DIR)/duck.c                                   \
			$(SRC_DIR)/event.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my re
	make -C lib/my_getopt re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:		clean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
