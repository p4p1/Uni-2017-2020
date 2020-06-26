##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

LFLAGS= -g3 -L./lib -lmy -lmy_getopt

NAME=	my_ls

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c                                    \
			$(SRC_DIR)/sort.c                                    \
			$(SRC_DIR)/count.c                                   \
			$(SRC_DIR)/padding.c                                 \
			$(SRC_DIR)/recursive.c                               \
			$(SRC_DIR)/time.c                                    \
			$(SRC_DIR)/error.c                                   \
			$(SRC_DIR)/dir.c                                     \
			$(SRC_DIR)/disp.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my/ re
	make -C lib/my_getopt/ re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my/ clean
	make -C lib/my_getopt/ clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my/ fclean
	make -C lib/my_getopt/ fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
