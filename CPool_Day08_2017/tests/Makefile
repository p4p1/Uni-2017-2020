##
## EPITECH PROJECT, 2017
##
## File decription:
## Makefile for unit tests.

SRC_DIR=	$(realpath ..)

SRC=		$(SRC_DIR)/my_strdup.c \
			$(SRC_DIR)/concat_params.c \
			$(SRC_DIR)/my_show_word_array.c \
			$(SRC_DIR)/my_str_to_word_array.c \
			$(SRC_DIR)/convert_base.c

SRC_UT_DIR=	$(realpath .)

SRC_UT=		$(SRC_UT_DIR)/tests_my_strdup.c \
			$(SRC_UT_DIR)/tests_concat_params.c \
			$(SRC_UT_DIR)/tests_my_show_word_array.c \
			$(SRC_UT_DIR)/tests_my_str_to_word_array.c \
			$(SRC_UT_DIR)/tests_convert_base.c

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)
GCDA=		$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)
GCNO=		$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)

CFLAGS=		-Wall -Wextra --coverage
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
