##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a Makefile for tests
##

SRC_DIR=	$(realpath .)


LIB_DIR=	$(realpath ./../src)
LIB_SRC=	$(LIB_DIR)/integers/number_len.c                   \
			$(LIB_DIR)/integers/get_digit.c                    \
			$(LIB_DIR)/integers/my_swap.c                      \
			$(LIB_DIR)/integers/is_digit.c                     \
			$(LIB_DIR)/nbr/my_getnbr.c                         \
			$(LIB_DIR)/nbr/my_put_nbr.c                        \
			$(LIB_DIR)/nbr/my_putnbr_base.c                    \
			$(LIB_DIR)/str/my_putstr.c                         \
			$(LIB_DIR)/str/my_revstr.c                         \
			$(LIB_DIR)/str/my_showstr.c                        \
			$(LIB_DIR)/str/my_strcapitalize.c                  \
			$(LIB_DIR)/str/my_strcat.c                         \
			$(LIB_DIR)/str/my_strcmp.c                         \
			$(LIB_DIR)/str/my_strcpy.c                         \
			$(LIB_DIR)/str/my_strdup.c                         \
			$(LIB_DIR)/str/my_strlen.c                         \
			$(LIB_DIR)/str/my_strncat.c                        \
			$(LIB_DIR)/str/my_strncmp.c                        \
			$(LIB_DIR)/str/my_strncpy.c                        \
			$(LIB_DIR)/str/my_strstr.c                         \
			$(LIB_DIR)/char/is_char.c                          \
			$(LIB_DIR)/char/my_putchar.c                       \
			$(LIB_DIR)/my_printf/my_printf.c                   \
			$(LIB_DIR)/my_printf/my_printf_flag.c              \
			$(LIB_DIR)/my_printf/my_printf_usigned.c           \
			$(LIB_DIR)/my_printf/my_printf_padding.c           \
			$(LIB_DIR)/my_printf/my_printf_color.c             \
			$(LIB_DIR)/my_printf/my_printf_pointers.c

SRC_UT=		$(SRC_DIR)/redirect.c                \
			$(SRC_DIR)/tests_basic.c             \
			$(SRC_DIR)/tests_unsigned.c          \
			$(SRC_DIR)/tests_pound.c             \
			$(SRC_DIR)/tests_color.c             \
			$(SRC_DIR)/tests_return.c            \
			$(SRC_DIR)/tests_other.c

GCDA_FILES=	$(LIB_SRC:.c=.gcda) $(SRC_UT:.c=.gcda)
GCNO_FILES=	$(LIB_SRC:.c=.gcno) $(SRC_UT:.c=.gcno)
OBJ=		$(LIB_SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS= 	-Wall -Wextra --coverage -I./include -I../include

LDFLAGS=	-lcriterion -lgcov

NAME=		units

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ../ re
		cc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -rf $(OBJ)
		rm -rf ../libmy.a
		rm -rf $(GCDA_FILES)
		rm -rf $(GCNO_FILES)

fclean: 	clean
		rm -f $(NAME)

re: fclean all
