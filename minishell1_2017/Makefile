##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -I./include

LFLAGS=	-L./lib -lmy

NAME=	mysh

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c                                             \
			$(SRC_DIR)/destroy.c                                          \
			$(SRC_DIR)/init.c                                             \
			$(SRC_DIR)/prompt/prompt.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my/ re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my/ clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my/ fclean
	@rm -rf lib/*.a
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
