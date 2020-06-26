/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** function getting the user's input.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *get_the_line(int *err, int status)
{
	size_t bufsize = 0;
	ssize_t rd = 0;
	char *line = NULL;

	rd = getline(&line, &bufsize, stdin);
	if (rd == -1) {
		*err = -1;
		exit(status);
	} else if (!line)
		exit(84);
	line[my_strlen(line) -1] = '\0';
	return (line);
}
