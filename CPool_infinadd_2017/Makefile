##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile infin_add
##

.SUFFIXES: .c .o

CC=		gcc
CP=		cp -r
FLAGS=	-Wall -Wextra -Werror -I./include
LFLAGS=	-L./lib/ -lmy

NAME=	infin_add

SRC_DIR=	$(realpath ./srcs)
SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/char_to_int.c \
			$(SRC_DIR)/add_values.c \
			$(SRC_DIR)/sign.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my re
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
