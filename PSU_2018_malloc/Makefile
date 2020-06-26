##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=				gcc

FLAGS=			-g3 -Wall -Wextra -Werror -I./include

NAME=			libmy_malloc.so

INCLUDE_DIR=	./include
INCLUDE=		$(INCLUDE_DIR)/

SRC_DIR=		./srcs
SRC=			$(SRC_DIR)/malloc.c \
				$(SRC_DIR)/realloc.c \
				$(SRC_DIR)/free.c \
				$(SRC_DIR)/show_alloc_mem.c \
				$(SRC_DIR)/list.c

OBJ=			$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -fPIC -shared -o $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -fPIC -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:			clean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
