##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-g3 -Wall -Wextra -Werror -I./include

NAME=	libgnl.a

INCLUDE_DIR=	./include
INCLUDE=		$(INCLUDE_DIR)/gnl.h

SRC_DIR=	./srcs
SRC=		$(SRC_DIR)/gnl.c                                 \

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

debug:	all test.c
	gcc debug/test.c -L./ -lgnl -I./include/

$(NAME):	$(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(NAME) ../
	$(CP) $(INCLUDE) ../../include/

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
