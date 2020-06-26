##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile lib
##

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-Wall -Wextra -I./include

NAME=	libmy.a

INCLUDE_DIR=	$(realpath ./include)
INCLUDE=		$(INCLUDE_DIR)/my.h                   \
				$(INCLUDE_DIR)/my_printf.h

SRC_DIR=	$(realpath ./src)
SRC=		$(SRC_DIR)/get_digit.c                    \
			$(SRC_DIR)/number_len.c                   \
			$(SRC_DIR)/my_getnbr.c                    \
			$(SRC_DIR)/my_put_nbr.c                   \
			$(SRC_DIR)/my_putchar.c                   \
			$(SRC_DIR)/my_putnbr_base.c               \
			$(SRC_DIR)/my_putstr.c                    \
			$(SRC_DIR)/my_revstr.c                    \
			$(SRC_DIR)/my_showstr.c                   \
			$(SRC_DIR)/my_strcapitalize.c             \
			$(SRC_DIR)/my_strcat.c                    \
			$(SRC_DIR)/my_strcmp.c                    \
			$(SRC_DIR)/my_strcpy.c                    \
			$(SRC_DIR)/my_strdup.c                    \
			$(SRC_DIR)/my_strlen.c                    \
			$(SRC_DIR)/my_strncat.c                   \
			$(SRC_DIR)/my_strncmp.c                   \
			$(SRC_DIR)/my_strncpy.c                   \
			$(SRC_DIR)/my_strstr.c                    \
			$(SRC_DIR)/my_swap.c                      \
			$(SRC_DIR)/is_digit.c                     \
			$(SRC_DIR)/is_char.c                      \
			$(SRC_DIR)/my_printf/my_printf.c          \
			$(SRC_DIR)/my_printf/my_printf_flag.c     \
			$(SRC_DIR)/my_printf/my_printf_usigned.c  \
			$(SRC_DIR)/my_printf/my_printf_padding.c  \
			$(SRC_DIR)/my_printf/my_printf_pointers.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(NAME) ../
	$(CP) $(INCLUDE) ../../include

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
