##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

LFLAGS= -L./lib -lmy

NAME=	fractals

SRC_DIR=	./srcs/
SRC=		$(SRC_DIR)main.c		\
			$(SRC_DIR)expander.c	\
			$(SRC_DIR)error.c	\
			$(SRC_DIR)fract.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

DEBUG:		all
	./$(NAME) 2 "##@#." "..@.."
	./$(NAME) 1 "###@#.#@###" "...@...@..."
	./$(NAME) 0 "##@#." "..@.."

$(NAME):	$(OBJ) $(INCLUDE)
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
