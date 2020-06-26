##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME=	funEvalExpr
CP=	cp -r
CC=	stack build

all:	$(NAME)

$(NAME):
	stack path --local-install-root
	$(CC);cp `stack path --local-install-root`/bin/evalexpr-exe ./$(NAME)


clean: fclean

fclean:
	rm -rf $(NAME)

re: fclean all
