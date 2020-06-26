##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-g3 -Wall -Wextra -I./include

LFLAGS=	-L./lib -lmy -lmy_fgets

NAME=	matchstick

SRC_DIR=	$(realpath ./srcs)
SRC=		$(SRC_DIR)/main.c                                    \
			$(SRC_DIR)/init.c                                    \
			$(SRC_DIR)/destroy.c                                 \
			$(SRC_DIR)/user.c                                    \
			$(SRC_DIR)/bot.c                                     \
			$(SRC_DIR)/algo.c                                    \
			$(SRC_DIR)/infi.c                                    \
			$(SRC_DIR)/match.c                                   \
			$(SRC_DIR)/disp.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my/ re
	make -C lib/my_fgets/ re
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my/ clean
	make -C lib/my_fgets/ clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my/ fclean
	make -C lib/my_fgets/ fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
