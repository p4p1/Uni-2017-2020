##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-g3 -Wall -Wextra -Werror -I./include

LFLAGS=	-L./lib -lmy

NAME=	cesar

SRC_DIR=	./srcs
SRC=		$(SRC_DIR)/main.c		\
			$(SRC_DIR)/cesar.c		\
			$(SRC_DIR)/file.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
