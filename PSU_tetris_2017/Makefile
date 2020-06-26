##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-g3 -Wall -Wextra -Werror -I./include

LFLAGS= -L./lib -lmy -lmy_fgets -lclist -lncurses

NAME=	tetris

SRC_DIR=	./srcs
SRC=		$(SRC_DIR)/main.c                    \
			$(SRC_DIR)/init.c                    \
			$(SRC_DIR)/tab.c                     \
			$(SRC_DIR)/debug.c                   \
			$(SRC_DIR)/get_files.c               \
			$(SRC_DIR)/parser/get_file.c         \
			$(SRC_DIR)/parser/valid_line.c       \
			$(SRC_DIR)/parser/pos.c              \
			$(SRC_DIR)/parser/sort.c             \
			$(SRC_DIR)/tab_func/big.c            \
			$(SRC_DIR)/tab_func/smol_d_to_p.c    \
			$(SRC_DIR)/tab_func/smol_q_to_w.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my/
	make -C lib/my_fgets/
	make -C lib/clist/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my/ clean
	make -C lib/my_fgets/ clean
	make -C lib/clist/ clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my/ fclean
	make -C lib/my_fgets/ fclean
	make -C lib/clist/ fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
