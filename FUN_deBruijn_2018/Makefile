##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC=				stack build

NAME=			deBruijn

all:
	stack path --local-install-root
	$(CC);cp `stack path --local-install-root`/bin/deBruijn-exe ./$(NAME)

clean: fclean

fclean:
	rm -rf $(NAME)

re: fclean all
