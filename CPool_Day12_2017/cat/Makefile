#
# EPITECH PROJECT, 2017
# Makefile
# File description:
# Compile lib
#

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-Wall -Wextra -Werror
LFLAGS=	-L./lib/ -lmy

NAME=	cat

SRC_DIR=	$(realpath .)
SRC=		$(SRC_DIR)/cat.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $< $(LFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
