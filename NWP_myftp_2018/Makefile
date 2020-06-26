##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=				gcc

FLAGS=			-g3 -Wall -Wextra -Werror -I./include

LFLAGS=			-L./lib

NAME=			myftp

INCLUDE_DIR=	./include
INCLUDE=		$(INCLUDE_DIR)/myftp.h

SRC_DIR=		./src
SRC=			$(SRC_DIR)/main.c \
				$(SRC_DIR)/network.c \
				$(SRC_DIR)/handle.c \
				$(SRC_DIR)/res.c \
				$(SRC_DIR)/cmd.c \
				$(SRC_DIR)/dir.c

OBJ=			$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:			clean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
