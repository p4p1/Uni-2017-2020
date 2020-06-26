#
# EPITECH PROJECT, 2017
#
# File decription:
# Makefile for unit tests.

SRC_DIR=	$(realpath ..)

SRC=		$(SRC_DIR)/rush3.c \
			$(SRC_DIR)/getlen.c \
			$(SRC_DIR)/gen_line.c \
			$(SRC_DIR)/gen_line_cond.c

SRC_UT_DIR=	$(realpath .)

SRC_UT=		$(SRC_UT_DIR)/tests_disp_rush.c \
			$(SRC_UT_DIR)/tests_getlen.c \
			$(SRC_UT_DIR)/tests_gen_line.c

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)
GCDA=		$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)
GCNO=		$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)

CFLAGS=		-Wall -Wextra --coverage -I../include
LDFLAGS=	-lcriterion -lgcov -L../lib/my/ -lmy
NAME=		units

all:		$(NAME) clean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf $(GCDA)
	rm -rf $(GCNO)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
