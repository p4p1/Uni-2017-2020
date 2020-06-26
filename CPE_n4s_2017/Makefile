##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

ifeq ($(debug),1)
FLAGS+= -g3
endif

LFLAGS= -L./lib -lmy -lgnl

NAME=	ai

SRC_DIR=	./srcs
SRC=		$(SRC_DIR)/main.c	\
			$(SRC_DIR)/race.c\

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	@make -C lib/my
	@make -C lib/gnl
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make -C lib/my clean
	@make -C lib/gnl clean
	@rm -rf $(OBJ)

fclean:		clean
	@make -C lib/my clean fclean
	@make -C lib/gnl fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
