##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a Makefile for tests
##

.SUFFIXES:	.c.o

CC=			gcc

CFLAGS=		-Wall -Wextra -Werror --coverage -I../include -I./include
LDFLAGS=	-lcriterion -lgcov

NAME=		units

SRC_DIR=	$(realpath ./../srcs/)
SRC=		$(SRC_DIR)/debug.c                                   \
			$(SRC_DIR)/str_util.c

SRC_UT_DIR=	$(realpath .)
SRC_UT=		$(SRC_UT_DIR)/tests_main.c                \
			$(SRC_UT_DIR)/redirect.c

GCDA_FILES=	$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)
GCNO_FILES=	$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)
OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)


all:		$(NAME)

run:
		@./$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ)
		rm -rf $(GCDA_FILES)
		rm -rf $(GCNO_FILES)

fclean:		clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re
