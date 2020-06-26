#
# EPITECH PROJECT, 2017
#
# File description:
#
#

SRC_DIR=	$(realpath ..)

# Must list all project files without the main() function
# Criterion uses its own main() ;
# having a main() in any .c file will have the build fail

SRC=		$(SRC_DIR)/display.c \
			$(SRC_DIR)/language.c \
			$(SRC_DIR)/get_occurence.c \
			$(SRC_DIR)/arguments.c \
			$(SRC_DIR)/error.c

SRC_UT_DIR=	$(realpath .)

# Must list all files containing unit tests
SRC_UT=		$(SRC_UT_DIR)/tests_display.c \
			$(SRC_UT_DIR)/tests_languages.c \
			$(SRC_UT_DIR)/tests_error.c

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)
GCDA=		$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)
GCNO=		$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)

CFLAGS=		-Wall -Wextra --coverage
LDFLAGS=	-lcriterion -lgcov -L../lib/my -lmy
NAME=		units

all:		$(NAME) clean
$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
	rm -f $(OBJ)
	rm -rf $(GCDA)
	rm -rf $(GCNO)
fclean:		clean
	rm -f $(NAME)
re:		fclean all
