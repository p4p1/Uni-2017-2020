#
# EPITECH PROJECT, 2017
#
# File decription:
# Makefile for unit tests.

SRC_DIR=	$(realpath ..)

SRC=		$(SRC_DIR)/my_strcat.c \
			$(SRC_DIR)/my_strncat.c \
			$(SRC_DIR)/task04/my_print_params.c \
			$(SRC_DIR)/task05/my_rev_params.c \
			$(SRC_DIR)/task06/my_sort_params.c

SRC_UT_DIR=	$(realpath .)

SRC_UT=		$(SRC_UT_DIR)/tests_my_strcat.c \
			$(SRC_UT_DIR)/tests_my_strncat.c \
			$(SRC_UT_DIR)/tests_my_print_params.c \
			$(SRC_UT_DIR)/tests_my_rev_params.c \
			$(SRC_UT_DIR)/tests_my_sort_params.c

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)
GCDA=		$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)
GCNO=		$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)

CFLAGS=		-Wall -Wextra -Werror --coverage
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
