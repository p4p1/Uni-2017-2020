##
## EPITECH PROJECT, 2019
## ftrace
## File description:
## Makefile
##

NAME	=	ftrace

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -pedantic

CPPFLAGS=	-Iinclude

SRC_DIR	=	src
SRC	=	$(SRC_DIR)/main.c \
		$(SRC_DIR)/ftrace.c \
		$(SRC_DIR)/disp.c \
		$(SRC_DIR)/elf_data.c \
		$(SRC_DIR)/tools.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
