/*
** EPITECH PROJECT, 2017
** test.c
** File description:
** <..>
*/

#include "gnl.h"

int main(void)
{
	char	*line = gnl(0);

	while (line) {
		printf("ret = %s\n", line);
		free(line);
		line = gnl(0);
	}
}
