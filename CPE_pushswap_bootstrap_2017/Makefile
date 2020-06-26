##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Make file for the bistromatic
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror --coverage -I./include

LFLAGS=	-lcriterion -lgcov

NAME=	units

SRC_DIR=	$(realpath .)

SRC=		$(SRC_DIR)/swap_elem.c \
			$(SRC_DIR)/tests/tests_swap_elem.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:		clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
