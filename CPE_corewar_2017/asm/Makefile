##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-g3 -Wall -Wextra -Werror -I./include

LFLAGS= -L./lib -lmy -lmy_fgets -lclist -lmy_getopt

NAME=	asm

SRC_DIR=	./srcs
SRC=		$(SRC_DIR)/main.c               \
			$(SRC_DIR)/op.c                 \
			$(SRC_DIR)/lexer/lex.c          \
			$(SRC_DIR)/error/files.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my/
	make -C lib/my_fgets/
	make -C lib/my_getopt/
	make -C lib/clist/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my/ clean
	make -C lib/my_fgets/ clean
	make -C lib/my_getopt/ clean
	make -C lib/clist/ clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my/ fclean
	make -C lib/my_fgets/ fclean
	make -C lib/my_getopt/ fclean
	make -C lib/clist/ fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
