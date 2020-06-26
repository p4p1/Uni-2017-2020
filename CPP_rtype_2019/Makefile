##
## EPITECH PROJECT, 2019
## makefile
## File description:
## tests
##

CC	:=	g++

SRC	=	main.cpp	\
		Menu.cpp

NAME	=	rtype

CFLAGS	+=	-W -Wall -Wextra -Werror

CPPFLAGS	+=	-Iinclude

LIBS	+=	-L -lsfml -lsfml-graphics -lsfml-window -lsfml-system

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LIBS)

clean:
			rm -rf $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

.PHONY: all re clean fclean