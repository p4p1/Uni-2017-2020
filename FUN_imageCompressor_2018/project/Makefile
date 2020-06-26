##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

BIN	=	$(shell stack path --local-install-root)/bin/project-exe

NAME	=	imageCompressor


all:
	stack build
	cp $(BIN) $(NAME)

clean:
	stack clean

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
