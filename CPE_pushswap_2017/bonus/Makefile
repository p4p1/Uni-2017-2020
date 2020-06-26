##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-g3 -Wall -Wextra -I./include

LFLAGS= -L./lib -lmy -lmy_getopt
ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LFLAGS+=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system
else
LFLAGS+=	-lc_graph_prog
endif

NAME=	push_swap

SRC_DIR=	$(realpath ./srcs)
SRC=		$(SRC_DIR)/main.c      \
			$(SRC_DIR)/put.c       \
			$(SRC_DIR)/get.c       \
			$(SRC_DIR)/rotate.c    \
			$(SRC_DIR)/revrotate.c \
			$(SRC_DIR)/string.c    \
			$(SRC_DIR)/graph.c     \
			$(SRC_DIR)/pixel.c     \
			$(SRC_DIR)/init.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my re
	make -C lib/my_getopt re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	make -C lib/my_getopt clean
	make -C lib/my/ clean

fclean:		clean
	@rm -rf $(NAME)
	make -C lib/my_getopt fclean
	make -C lib/my/ fclean

re: clean all

.PHONY: clean fclean re
