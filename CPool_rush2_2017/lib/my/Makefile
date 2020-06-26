#
# EPITECH PROJECT, 2017
# Makefile
# File description:
# Compile lib
#

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-Wall -Wextra

NAME=	libmy.a

INCLUDE_DIR=	$(realpath .)
INCLUDE=		$(INCLUDE_DIR)/my.h

SRC_DIR=	$(realpath .)
SRC=		$(SRC_DIR)/my_compute_factorial_it.c  \
			$(SRC_DIR)/my_print_digits.c          \
			$(SRC_DIR)/my_str_islower.c	          \
			$(SRC_DIR)/my_compute_factorial_rec.c \
			$(SRC_DIR)/my_print_revalpha.c        \
			$(SRC_DIR)/my_str_islpha.c            \
			$(SRC_DIR)/my_compute_power_it.c      \
			$(SRC_DIR)/my_putchar.c               \
			$(SRC_DIR)/my_str_isnum.c             \
			$(SRC_DIR)/my_compute_power_rec.c     \
			$(SRC_DIR)/my_putnbr_base.c           \
			$(SRC_DIR)/my_str_isprintable.c       \
			$(SRC_DIR)/my_compute_square_root.c   \
			$(SRC_DIR)/my_put_nbr.c               \
			$(SRC_DIR)/my_str_isupper.c           \
			$(SRC_DIR)/my_evil_str.c              \
			$(SRC_DIR)/my_putstr.c                \
			$(SRC_DIR)/my_strlen.c                \
			$(SRC_DIR)/my_find_prime_sup.c        \
			$(SRC_DIR)/my_revstr.c                \
			$(SRC_DIR)/my_strlowcase.c            \
			$(SRC_DIR)/my_getnbr_base.c           \
			$(SRC_DIR)/my_showmem.c               \
			$(SRC_DIR)/my_strncat.c               \
			$(SRC_DIR)/my_getnbr.c                \
			$(SRC_DIR)/my_showstr.c               \
			$(SRC_DIR)/my_strncmp.c               \
			$(SRC_DIR)/my_isneg.c                 \
			$(SRC_DIR)/my_sort_int_array.c        \
			$(SRC_DIR)/my_strncpy.c               \
			$(SRC_DIR)/my_is_prime.c              \
			$(SRC_DIR)/my_strcapitalize.c         \
			$(SRC_DIR)/my_strstr.c                \
			$(SRC_DIR)/my_print_alpha.c           \
			$(SRC_DIR)/my_strcat.c                \
			$(SRC_DIR)/my_strupcase.c             \
			$(SRC_DIR)/my_print_comb2.c           \
			$(SRC_DIR)/my_strcmp.c                \
			$(SRC_DIR)/my_swap.c                  \
			$(SRC_DIR)/my_print_comb.c            \
			$(SRC_DIR)/my_strcpy.c                \
			$(SRC_DIR)/number_util_func.c         \
			$(SRC_DIR)/my_print_combn.c           \
			$(SRC_DIR)/my_str_isalpha.c
OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(NAME) ../
	$(CP) *.h ../../include

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
