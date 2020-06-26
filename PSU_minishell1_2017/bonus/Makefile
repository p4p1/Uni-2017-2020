##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -I./include

LFLAGS=	-L./lib -lmy -lmy_getopt -lclist

NAME=	mysh

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c                                             \
			$(SRC_DIR)/destroy.c                                          \
			$(SRC_DIR)/get_path.c                                         \
			$(SRC_DIR)/count.c                                            \
			$(SRC_DIR)/env.c                                              \
			$(SRC_DIR)/function_pointers.c                                \
			$(SRC_DIR)/signal_error.c                                     \
			$(SRC_DIR)/command.c                                          \
			$(SRC_DIR)/init.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my/ re
	make -C lib/my_getopt/ re
	make -C lib/clist/ re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my/ clean
	make -C lib/my_getopt/ clean
	make -C lib/clist/ clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my/ fclean
	make -C lib/my_getopt/ fclean
	make -C lib/clist/ fclean
	@rm -rf lib/*.a
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
