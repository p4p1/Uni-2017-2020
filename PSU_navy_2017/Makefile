##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -I./include

LFLAGS=	-L./lib -lmy -lmy_getopt -lclist -lmy_fgets

NAME=	navy

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c                                          \
			$(SRC_DIR)/init.c                                          \
			$(SRC_DIR)/disp.c                                          \
			$(SRC_DIR)/set_boat.c                                      \
			$(SRC_DIR)/cdat.c                                          \
			$(SRC_DIR)/map.c                                           \
			$(SRC_DIR)/string.c                                        \
			$(SRC_DIR)/connect.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	@make -C lib/my/ re
	@make -C lib/clist/ re
	@make -C lib/my_getopt/ re
	@make -C lib/my_fgets/ re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make -C lib/my/ clean
	@make -C lib/clist/ clean
	@make -C lib/my_getopt/ clean
	@make -C lib/my_fgets/ clean
	@rm -rf $(OBJ)

fclean:		clean
	@make -C lib/my/ fclean
	@make -C lib/clist/ fclean
	@make -C lib/my_getopt/ fclean
	@make -C lib/my_fgets/ fclean
	@rm -rf lib/*.a
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
