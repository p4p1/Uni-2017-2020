/*
** EPITECH PROJECT, 2018
** modif_name.c
** File description:
** modif name
*/

#include "my.h"

int check_end(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '/')
			return (1);
		i ++;
	}
	return (0);
}

void modif_name(args *command)
{
	if (command->filename[0] == '.') {
		command->filename ++;
		command->filename ++;
	}
	return;
}
