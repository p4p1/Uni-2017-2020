##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile lib
##

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-Wall -Wextra -Werror -I./include

NAME=	libclist.a

INCLUDE_DIR=	$(realpath ./include)
INCLUDE=		$(INCLUDE_DIR)/clist.h \
				$(INCLUDE_DIR)/stack.h \
				$(INCLUDE_DIR)/queue.h

SRC_DIR=	$(realpath ./src)
SRC=		$(SRC_DIR)/add_queue.c \
			$(SRC_DIR)/add_stack.c \
			$(SRC_DIR)/disp_queue.c \
			$(SRC_DIR)/disp_stack.c \
			$(SRC_DIR)/dump_stack_to_queue.c \
			$(SRC_DIR)/move_queue.c \
			$(SRC_DIR)/my_print_nbr.c \
			$(SRC_DIR)/my_putastr.c \
			$(SRC_DIR)/my_strdp.c \
			$(SRC_DIR)/pop_stack.c \
			$(SRC_DIR)/pop_stack_to_queue.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(NAME) ../
	$(CP) $(INCLUDE) ../../include/

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
