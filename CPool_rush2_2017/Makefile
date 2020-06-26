#
# EPITECH PROJECT, 2017
# Makefile
# File description:
# Compile lib
#

CC=		gcc
FLAGS=	-Wall -Wextra
LFLAGS=	-L./lib/my -lmy

NAME=	rush2

SRC_DIR=	$(realpath .)
SRC=		$(SRC_DIR)/arguments.c \
			$(SRC_DIR)/display.c \
			$(SRC_DIR)/error.c \
			$(SRC_DIR)/get_occurence.c \
			$(SRC_DIR)/language.c \
			$(SRC_DIR)/main.c
OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $< $(LFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
