##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## rule file
##

NAME	=	42sh

CC	=	gcc

INCLUDE =	-I./include/ -L./lib/my/ -lmy

CFLAGS +=	-Wall -Wextra -g3 $(INCLUDE)

SRC	=	./lib/my/my_putchar.c	\
		./lib/my/my_put_nbr.c	\
		./lib/my/my_putstr.c	\
		./lib/my/my_getnbr.c	\
		./lib/my/my_revstr.c	\
		./lib/my/my_strlen.c	\
		./src/main.c		\
		./src/get_the_line.c	\
		./src/concat.c		\
		./src/check_built.c	\
		./src/built.c		\
		./src/search_bin.c	\
		./src/modif_name.c	\
		./src/modif_env.c	\
		./src/go_cd.c		\
		./src/make_good.c	\
		./src/handle_signal.c	\
		./src/do_command.c	\
		./src/do_pipe.c		\
		./src/get_pipe.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc ./lib/my/libmy.a $(OBJ)
		$(CC) -o $(NAME) $(SRC) $(INCLUDE)

clean:
	$(RM) $(OBJ)
	$(RM) *~;
	$(RM) \#*\#;

fclean :	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	fclean all re clean
