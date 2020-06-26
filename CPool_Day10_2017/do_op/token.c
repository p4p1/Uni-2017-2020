/*
** EPITECH PROJECT, 2017
** token.c
** File description:
** file to get and process the tokens given in parameter
*/

#include "do_op.h"

char is_token(char ch)
{
	char	token_list[6] = { '+', '-', '*', '/', '%', 0 };
	int	i = 0;

	for (i = 0; i < 6; i++) {
		if (ch == token_list[i])
			break;
	}
	return (i);
}

char token_scanner(char *str)
{
	int	i = 0;

	for (i = 0; *(str + i) != '\0'; i++) {
		if (is_token(*(str + i)) < 5)
			break;
	}
	return (*(str + i));
}
