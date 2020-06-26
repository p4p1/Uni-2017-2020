##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a Makefile for tests
##

.SUFFIXES:	.c.o

CC=			gcc

CFLAGS=		-Wall -Wextra -Werror --coverage -I../include -I./include
LDFLAGS=	-L../lib/ -lcriterion -lgcov -lmy -lmy_fgets

NAME=		units

SRC_DIR=	$(realpath ./../srcs/)
SRC=		$(SRC_DIR)/bsq.c                     \
			$(SRC_DIR)/sol.c                     \
			$(SRC_DIR)/algo.c                    \
			$(SRC_DIR)/utils.c

SRC_UT_DIR=	$(realpath .)
SRC_UT=		$(SRC_UT_DIR)/debug.c                \
			$(SRC_UT_DIR)/simple_1x1.c

GCDA_FILES=	$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)
GCNO_FILES=	$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)
OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)


all:		$(NAME)

run:
		@./$(NAME)

$(NAME):	$(OBJ)
		make -C ../lib/my re
		make -C ../lib/my_fgets re
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ)
		make -C ../lib/my clean
		make -C ../lib/my_fgets clean
		rm -rf $(GCDA_FILES)
		rm -rf $(GCNO_FILES)

fclean:		clean
		make -C ../lib/my fclean
		make -C ../lib/my_fgets fclean
		rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re
