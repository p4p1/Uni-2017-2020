##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile lib
##

# defining my own suffixes for the makefile
.SUFFIXES: .asm .o

CC=		nasm
CP=		cp -r
AR=		ar cr
FLAGS= -felf64 -Wall -Werror

NAME=	libasm.so

SRC_DIR=	./src
SRC=		$(SRC_DIR)/strlen.asm \
			$(SRC_DIR)/strchr.asm \
			$(SRC_DIR)/memset.asm \
			$(SRC_DIR)/memcpy.asm \
			$(SRC_DIR)/strcmp.asm \
			$(SRC_DIR)/strncmp.asm \
			$(SRC_DIR)/rindex.asm \
			$(SRC_DIR)/strpbrk.asm \
			$(SRC_DIR)/strcspn.asm \
			$(SRC_DIR)/memmove.asm

OBJ=		$(SRC:.asm=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ld $(OBJ) -fPIC -shared -o $(NAME)

.asm.o:
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
