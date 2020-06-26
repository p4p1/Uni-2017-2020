##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=				gcc

FLAGS=			-Wall -Wextra -Werror -I./include

LFLAGS=			-L./lib

NM=			my_nm
OBJDUMP=	my_objdump

INCLUDE_DIR=	./include
INCLUDE=		$(INCLUDE_DIR)/nm.h \
				$(INCLUDE_DIR)/objdump.h

SRC_NM_DIR=		./srcs/nm
NM_SRC=			$(SRC_NM_DIR)/main.c \
				$(SRC_NM_DIR)/list.c

SRC_OBJ_DIR=		./srcs/objdump
OBJ_SRC=			$(SRC_OBJ_DIR)/main.c

NM_OBJ=			$(NM_SRC:.c=.o)
OBJ_OBJ=			$(OBJ_SRC:.c=.o)

all:			$(NM) $(OBJDUMP)

$(NM):		$(NM_OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NM) $(NM_OBJ) $(LFLAGS)

$(OBJDUMP):		$(OBJ_OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(OBJDUMP) $(OBJ_OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(NM_OBJ)
	@rm -rf $(OBJ_OBJ)

fclean:			clean
	@rm -rf $(NM)
	@rm -rf $(OBJDUMP)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
