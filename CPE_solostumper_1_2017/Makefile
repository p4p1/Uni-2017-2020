##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

NAME=	hidenp

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c                                           \
			$(SRC_DIR)/str_util.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:		clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
