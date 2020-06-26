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
FLAGS=	-felf64 -Wall -Werror

NAME=	libmy_unistd.a

INCLUDE_DIR=	$(realpath ./include)
INCLUDE=		$(INCLUDE_DIR)/my_unistd.h

SRC_DIR=	$(realpath ./src)
SRC=		$(SRC_DIR)/my_write.asm \
			$(SRC_DIR)/my_read.asm

OBJ=		$(SRC:.asm=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(NAME) ../
	$(CP) $(INCLUDE) ../../include/

.asm.o:
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
