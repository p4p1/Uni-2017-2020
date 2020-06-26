/*
** EPITECH PROJECT, 2017
** arguments.c
** File description:
** find all the arguments
*/

#include "do_op.h"

int get_no(char *str)
{
	int	i = 0;
	int	flag = 0;

	if (!(*str < '9' && *str > '0') && *str != '-')
		return (0);
	while ((*(str + i) > '9' || *(str + i) < '0') && *(str + i) != '\0')
		i++;
	if (*(str + (i - 1)) == '-')
		flag = 1;
	if (flag)
		return (-1 * my_getnbr(str+i));
	return (my_getnbr(str+i));
}

