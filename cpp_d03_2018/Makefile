##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile lib
##

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-g3 -Wall -Wextra

NAME=	libstring.a

INCLUDE_DIR=	$(realpath ./)
INCLUDE=		$(INCLUDE_DIR)/string.h

SRC_DIR=	$(realpath ./)
SRC=		$(SRC_DIR)/init.c                              \
			$(SRC_DIR)/assign.c                            \
			$(SRC_DIR)/at.c                                \
			$(SRC_DIR)/clear.c                             \
			$(SRC_DIR)/size.c                              \
			$(SRC_DIR)/compare.c                           \
			$(SRC_DIR)/copy.c                              \
			$(SRC_DIR)/c_str.c                             \
			$(SRC_DIR)/empty.c                             \
			$(SRC_DIR)/find.c                              \
			$(SRC_DIR)/insert.c                            \
			$(SRC_DIR)/to_int.c                            \
			$(SRC_DIR)/split.c                             \
			$(SRC_DIR)/aff.c                               \
			$(SRC_DIR)/join.c                              \
			$(SRC_DIR)/substr.c                            \
			$(SRC_DIR)/append.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)
#$(CP) $(NAME) ../
#$(CP) $(INCLUDE) ../../include

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
