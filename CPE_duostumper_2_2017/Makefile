##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

LFLAGS= -L./lib -lmy -lmy_fgets

NAME=	connect4

SRC_DIR=	./srcs/
SRC=		$(SRC_DIR)main.c			\
			$(SRC_DIR)init.c			\
			$(SRC_DIR)destroy.c			\
			$(SRC_DIR)arg.c				\
			$(SRC_DIR)replace.c			\
			$(SRC_DIR)replace_chars.c	\
			$(SRC_DIR)end.c				\
			$(SRC_DIR)check.c			\
			$(SRC_DIR)display.c			\
			$(SRC_DIR)my_memset.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

val:	all
	valgrind ./$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my
	make -C lib/my_fgets
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	make -C lib/my_fgets clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/my_fgets fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
