##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a Makefile for tests
##
SRC_DIR=	$(realpath ..)

SRC=		$(SRC_DIR)/srcs/utils.c \

SRC_UT_DIR=	$(realpath .)

SRC_UT=		$(SRC_DIR)/tests/test_utils.c

GCDA_FILES=	$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)

GCNO_FILES=	$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS= 	-Wall -Wextra --coverage -I../include

LDFLAGS=	-lcriterion -lgcov -L../lib -lmy -lclist

NAME=		units

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ../lib/my/ re
		make -C ../lib/clist/ re
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(GCDA_FILES)
		rm -f $(GCNO_FILES)

fclean: 	clean
		rm -f $(NAME)

re: fclean all
