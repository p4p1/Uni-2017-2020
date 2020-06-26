##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=				gcc

FLAGS=			-g3 -Wall -Wextra -Werror -I./include

NAME=			myARPspoof

INCLUDE_DIR=	./include
INCLUDE=		$(INCLUDE_DIR)/myarpspoof.h

SRC_DIR=		./src
SRC=			$(SRC_DIR)/main.c \
				$(SRC_DIR)/getmymac.c \
				$(SRC_DIR)/convert.c \
				$(SRC_DIR)/getothermac.c \
				$(SRC_DIR)/getinterfaceinfo.c \
				$(SRC_DIR)/disp.c \
				$(SRC_DIR)/misc.c \
				$(SRC_DIR)/arp.c

OBJ=			$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:			clean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
