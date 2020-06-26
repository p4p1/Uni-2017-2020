##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -I./include

LFLAGS=	-L./lib -lmy -lmy_getopt
ifeq ($(shell cat /etc/*-release | grep "Fedora"), )
LFLAGS+=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system
else
LFLAGS+=	-lc_graph_prog
endif

NAME=	my_hunter

SRC_DIR=	$(realpath ./srcs)
SRC=		$(SRC_DIR)/main.c                                   \
			$(SRC_DIR)/init.c                                   \
			$(SRC_DIR)/destroy.c                                \
			$(SRC_DIR)/duck.c                                   \
			$(SRC_DIR)/event.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my re
	make -C lib/my_getopt re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	make -C lib/my_getopt clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/my_getopt fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
