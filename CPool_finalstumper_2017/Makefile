#
# EPITECH PROJECT, 2017
# Makefile
# File description:
# Compile lib
#

CC=		gcc
CP=		cp -r
FLAGS=	-Wall -Wextra -Werror -I./include
LFLAGS=	-L./lib/ -lmy

NAME=	rush3

SRC_DIR=	$(realpath .)
SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/rush3.c \
			$(SRC_DIR)/getlen.c \
			$(SRC_DIR)/gen_line_cond.c \
			$(SRC_DIR)/gen_line.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make -C lib/my/ clean
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
