#
# EPITECH PROJECT, 2017
# Makefile
# File description:
# makefile for unit tests
#

SRC_DIR=	$(realpath ..)

SRC=		$(SRC_DIR)/my_getnbr_base.c \
			$(SRC_DIR)/my_strcapitalize.c \
			$(SRC_DIR)/my_str_isnum.c \
			$(SRC_DIR)/my_strncpy.c   \
			$(SRC_DIR)/my_putnbr_base.c \
			$(SRC_DIR)/my_strcmp.c \
			$(SRC_DIR)/my_str_isprintable.c \
			$(SRC_DIR)/my_strstr.c \
			$(SRC_DIR)/my_revstr.c \
			$(SRC_DIR)/my_strcpy.c \
			$(SRC_DIR)/my_str_isupper.c \
			$(SRC_DIR)/my_strupcase.c       \
			$(SRC_DIR)/my_showmem.c         \
			$(SRC_DIR)/my_str_islower.c     \
			$(SRC_DIR)/my_strlowcase.c      \
			$(SRC_DIR)/my_showstr.c         \
			$(SRC_DIR)/my_str_isalpha.c      \
			$(SRC_DIR)/my_strncmp.c \
			/tmp/my_putchar.c


SRC_UT_DIR=	$(realpath .)

# Must list all files containing unit tests
SRC_UT=		$(SRC_UT_DIR)/tests_my_getnbr_base.c \
			$(SRC_UT_DIR)/tests_my_strcapitalize.c \
			$(SRC_UT_DIR)/tests_my_str_isnum.c \
			$(SRC_UT_DIR)/tests_my_strncpy.c   \
			$(SRC_UT_DIR)/tests_my_putnbr_base.c \
			$(SRC_UT_DIR)/tests_my_strcmp.c \
			$(SRC_UT_DIR)/tests_my_str_isprintable.c \
			$(SRC_UT_DIR)/tests_my_strstr.c \
			$(SRC_UT_DIR)/tests_my_revstr.c \
			$(SRC_UT_DIR)/tests_my_strcpy.c \
			$(SRC_UT_DIR)/tests_my_str_isupper.c \
			$(SRC_UT_DIR)/tests_my_strupcase.c       \
			$(SRC_UT_DIR)/tests_my_showmem.c         \
			$(SRC_UT_DIR)/tests_my_str_islower.c     \
			$(SRC_UT_DIR)/tests_my_strlowcase.c      \
			$(SRC_UT_DIR)/tests_my_showstr.c         \
			$(SRC_UT_DIR)/tests_my_str_isalpha.c      \
			$(SRC_UT_DIR)/tests_my_strncmp.c

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)
GCDA=		$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)
GCNO=		$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)

CFLAGS=		-Wall -Wextra --coverage
LDFLAGS=	-lcriterion -lgcov
NAME=		units

all:		$(NAME) clean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -rf $(GCDA)
	rm -rf $(GCNO)

fclean:		clean
	rm -f $(NAME)

re:		fclean all
