##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Make file for the bistromatic
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

LFLAGS= -L./lib -lmy -lclist

NAME=	calc

SRC_DIR=	$(realpath ./srcs/)

SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/addinf.c \
			$(SRC_DIR)/subinf.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/utils_2.c \
			$(SRC_DIR)/utils_3.c \
			$(SRC_DIR)/utils_4.c \
			$(SRC_DIR)/check.c \
			$(SRC_DIR)/multinf.c \
			$(SRC_DIR)/divinf.c \
			$(SRC_DIR)/modulo.c \
			$(SRC_DIR)/error.c \
			$(SRC_DIR)/eval_expr.c \
			$(SRC_DIR)/textsujet.c \
			$(SRC_DIR)/shunting_yard_alg.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C ./lib/my
	make -C ./lib/clist
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	make -C ./lib/my clean
	make -C ./lib/clist clean

fclean:		clean
	@rm -rf $(NAME)
	@rm -rf lib/*.a
	make -C ./lib/my fclean
	make -C ./lib/clist fclean

re: fclean all

.PHONY: clean fclean re
