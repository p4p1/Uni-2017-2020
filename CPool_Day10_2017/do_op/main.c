/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for the do-op
*/

#include "do_op.h"

int do_operation(int V1, char token, int V2)
{
	if (token == '+')
		my_put_nbr(V1 + V2);
	if (token == '-')
		my_put_nbr(V1 - V2);
	if (token == '/') {
		if (V2 == 0)
			return (-1);
		else
			my_put_nbr(V1 / V2);
	}
	if (token == '*')
		my_put_nbr(V1 * V2);
	if (token == '%') {
		if (V2 == 0)
			return (-2);
		else
			my_put_nbr(V1 % V2);
	}
	return (0);
}

int error_processing(int condition, char token)
{
	switch (condition) {
		case -1:
			my_putstr_err("Stop: division by zero\n");
			return (84);
			break;
		case -2:
			my_putstr_err("Stop: modulo by zero\n");
			return (84);
			break;
		default:
			break;
	}
	if (token == '\0') {
		my_putstr("0\n");
		return (84);
	} else {
		my_putchar('\n');
	}
	return (0);
}

int main(int ac, char **av)
{
	char	token = 0;
	int	V1 = 0;
	int	V2 = 0;
	int	condition = 0;

	if (ac != 4)
		return (84);
	token = token_scanner(av[2]);
	V1 = get_no(av[1]);
	V2 = get_no(av[3]);
	condition = do_operation(V1, token, V2);
	return (error_processing(condition, token));
}
