##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .cpp .o

CC=				g++

FLAGS=			-Wall -Wextra -I./include

LFLAGS=			-L./lib

NAME=			my_cat

SRC=			main.cpp

OBJ=			$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.cpp.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:			clean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
